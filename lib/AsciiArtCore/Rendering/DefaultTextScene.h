#ifndef __LIB_ASCII_ART_CORE__DEFAULT_TEXT_SCENE_H__
#define __LIB_ASCII_ART_CORE__DEFAULT_TEXT_SCENE_H__

#include <AsciiArtCore/Rendering/TextScene.h>

namespace AsciiArt
{
    namespace Rendering
    {
        template <class STREAM>
        class DefaultTextScene : public TextScene<STREAM, uchar[10][21] >
        {
        public:
            DefaultTextScene(void) : 
              TextScene( 0, 19, 0, 9),
              pixelMapSize_( 21*10 )
            {
                Clear();
            }
            virtual ~DefaultTextScene(void)
            {
                // We do not have ownership over the stream.
                // Client code is responsible for closing it.
            }


            virtual void Clear()
            {
                uint lineEndIndex = xMax_ + 1;

                //Hot fix
                int iMapBegin = (int)pixelMap_;
                int iMapEnd   = iMapBegin + pixelMapSize_;

                uchar* pMapBegin = (uchar*)pixelMap_;
                uchar* pMapEnd   = (uchar*)iMapEnd;

                std::fill( pMapBegin, pMapEnd, ' ' );
                for ( size_t y = 0; y <= yMax_; ++y )
                {
                    pixelMap_[y][lineEndIndex] = 0;
                }

                currentSymbol_ = '*';
            }



        private:
            uint pixelMapSize_;
        };
    }
}

#endif //__LIB_ASCII_ART_CORE__DEFAULT_TEXT_SCENE_H__
