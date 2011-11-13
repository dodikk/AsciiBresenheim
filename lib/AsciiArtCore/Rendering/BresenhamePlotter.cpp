#include "StdAfx.h"
#include "BresenhamePlotter.h"

using namespace AsciiArt::Core;
using namespace AsciiArt::Rendering;

BresenhamePlotter::BresenhamePlotter(void)
{
}

BresenhamePlotter::~BresenhamePlotter(void)
{
}


void BresenhamePlotter::DrawLinesBeginLinesEndOnSceneWithDelegate( 
                Lines_vt_ci beg, 
                Lines_vt_ci end,
                IScene* scene, 
                IPlotterDelegate* plotterDelegate )
{
    while ( beg != end )
    {
        plotterDelegate->PlotterWillDrawLine( this, &(*beg) );
        {
            this->DrawLineOnSceneWithDelegate( (*beg), scene  );
        }
        plotterDelegate->PlotterDidDrawLine( this, &(*beg) );
        ++beg;
    }
}

void BresenhamePlotter::DrawLineOnSceneWithDelegate( 
                const Line& line,
                IScene* scene )
{
    //TODO : actual implementation here
}
