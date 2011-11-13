#ifndef __LIB_ASCII_ART_CORE__BRESENHAME_PLOTTER_H__
#define __LIB_ASCII_ART_CORE__BRESENHAME_PLOTTER_H__

#include <AsciiArtCore\Rendering\IPlotter.h>

namespace AsciiArt
{
    namespace Rendering
    {
        class BresenhamePlotter : public IPlotter
        {
        public:
            BresenhamePlotter(void);
            virtual ~BresenhamePlotter(void);

        public:
            virtual void DrawLinesBeginLinesEndOnSceneWithDelegate( 
                Core::Lines_vt_ci beg, 
                Core::Lines_vt_ci end,
                IScene* scene, 
                IPlotterDelegate* plotterDelegate );

            virtual void DrawLineOnSceneWithDelegate( 
                const Core::Line& line,
                IScene* scene );

        private:
            void DrawHorizontalLine( CoordinateType xFrom, CoordinateType xTo, CoordinateType y, IScene* scene );
            void DrawVerticalLine( CoordinateType yFrom, CoordinateType yTo, CoordinateType x, IScene* scene );
        };
    }
}

#endif

