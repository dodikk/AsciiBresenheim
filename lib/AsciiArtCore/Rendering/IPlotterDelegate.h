#ifndef __LIB_ASCII_ART_CORE__PLOTTER_H__
#define __LIB_ASCII_ART_CORE__PLOTTER_H__

#include <AsciiArtCore/Types/CoreTypes.h>
#include <AsciiArtCore/Types/AsciiArtTypes.h>


namespace AsciiArt
{
    namespace  Core
    {
        class Line;
    }

    namespace Rendering
    {
        class IPlotter;
    }
}

namespace AsciiArt
{
    namespace Rendering
    {
        class IPlotterDelegate
        {
        public:
            IPlotterDelegate(void);
            virtual ~IPlotterDelegate(void);

        public:
            virtual void PlotterWillDrawLine( IPlotter* plotter, const Core::Line* line) = 0;
            virtual void PlotterDidDrawLine( IPlotter* plotter, const Core::Line* line) = 0;
        };
    }
}

#endif