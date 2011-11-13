#ifndef __LIB_ASCII_ART_CORE__RENDER_UTILS_H__
#define __LIB_ASCII_ART_CORE__RENDER_UTILS_H__

#include <AsciiArtCore/Types/AsciiArtTypes.h>
#include <AsciiArtCore/Types/CoreTypes.h>
#include <string>

namespace AsciiArt
{
    namespace Rendering
    {
        class RenderUtils
        {
        private:
            RenderUtils(void);
            ~RenderUtils(void);

        public:
            static uchar NextRenderSymbol( uchar renderSymbol );
            static bool PointInRange( 
                const Core::Point& point, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax );

            static void AssertPointInRange( 
                const Core::Point& point, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax );

            static void AssertLineInRange( 
                const Core::Line& line, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax );
        };
    }
}

#endif