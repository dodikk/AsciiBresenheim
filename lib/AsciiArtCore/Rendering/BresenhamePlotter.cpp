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
    if ( line.IsPoint() )
    {
        scene->SetPixelXY( line.StartPoint().GetX(), line.StartPoint().GetY() );
    }
    else if ( line.IsHorizontal() )
    {
        DrawHorizontalLine( 
            line.StartPoint().GetX(), line.EndPoint().GetX(), 
            line.StartPoint().GetY(),
            scene );
    }
    else if ( line.IsVertical() )
    {
        DrawVerticalLine( 
            line.StartPoint().GetY(), line.EndPoint().GetY(), 
            line.StartPoint().GetX(),
            scene );
    }



}

void BresenhamePlotter::DrawHorizontalLine( 
    CoordinateType xFrom, CoordinateType xTo, 
    CoordinateType y,
    IScene* scene )
{
    if ( xFrom > xTo )
    {
        std::swap( xFrom, xTo );
    }

    for ( CoordinateType x = xFrom; x <= xTo; ++x )
    {
        scene->SetPixelXY( x, y );
    }
}

void BresenhamePlotter::DrawVerticalLine( 
    CoordinateType yFrom, CoordinateType yTo, 
    CoordinateType x,
    IScene* scene )
{
    if ( yFrom > yTo )
    {
        std::swap( yFrom, yTo );
    }

    for ( CoordinateType y = yFrom; y <= yTo; ++y )
    {
        scene->SetPixelXY( x, y );
    }
}
 
