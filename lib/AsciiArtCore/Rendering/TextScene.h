#ifndef __LIB_ASCII_ART_CORE__TEXT_SCENE_H__
#define __LIB_ASCII_ART_CORE__TEXT_SCENE_H__

#include <AsciiArtCore/Rendering/IScene.h>
#include <AsciiArtCore/Rendering/IPlotter.h>
#include <AsciiArtCore/Rendering/IPlotterDelegate.h>
#include <AsciiArtCore/Rendering/RenderUtils.h>
#include <AsciiArtCore/Types/CoreTypes.h>
#include <algorithm>

namespace AsciiArt
{
    namespace Rendering
    {
        template <class STREAM, class PIXEL_MAP>
        class TextScene : 
            public IScene,
            public IPlotterDelegate
        {
        public:
            TextScene( 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax ) : 
            xMin_( xMin ), yMin_( yMin ),
            xMax_( xMax ), yMax_( yMax ),
            currentSymbol_( '*' ),
            renderingStream_( NULL )
            {
            }
            virtual ~TextScene(void)
            {
                // We do not have ownership over the stream.
                // Client code is responsible for closing it.
            }

        public:
            virtual void Clear() = 0;

            virtual void SetPixelXY( CoordinateType x, CoordinateType y )
            {
                pixelMap_[y][x] = currentSymbol_;
            }

            virtual void Render()
            {
                for ( size_t y = 0; y <= yMax_; ++y )
                {
                    (*renderingStream_) << pixelMap_[y] << std::endl;
                }
            }


        public:
            void PlotterWillDrawLine( IPlotter* plotter, const  Core::Line* line)
            {
                currentSymbol_ = RenderUtils::NextRenderSymbol( currentSymbol_ );
            }
            void PlotterDidDrawLine( IPlotter* plotter, const  Core::Line* line)
            {
                //IDLE
            }

        public:
            void SetStream( STREAM* renderingStream )
            {
                renderingStream_ = renderingStream;
            }

        public:
            const PIXEL_MAP* GetPixelMap() const
            {
                return &pixelMap_;
            }


        protected:
            STREAM* renderingStream_;
            PIXEL_MAP pixelMap_;

        protected:
            uint xMax_;
            uint xMin_;
            uint yMax_;
            uint yMin_;

            uchar currentSymbol_;
        };
    }
}

#endif //__LIB_ASCII_ART_CORE__TEXT_SCENE_H__

