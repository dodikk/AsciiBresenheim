#ifndef __LIB_ASCII_ART_CORE__ISCENE_H__
#define __LIB_ASCII_ART_CORE__ISCENE_H__

#include <AsciiArtCore/Types/CoreTypes.h>
#include <AsciiArtCore/Types/AsciiArtTypes.h>

namespace AsciiArt
{
    namespace Rendering
    {
        class IScene
        {
        protected:
            IScene(void);
            virtual ~IScene(void);

        public:
            virtual void SetPixelXY( CoordinateType x, CoordinateType y ) = 0;
            virtual void Render() = 0;
            virtual void Clear() = 0;
        };
    }
}

#endif //__LIB_ASCII_ART_CORE__ISCENE_H__