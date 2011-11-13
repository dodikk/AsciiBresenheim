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

float round( float value )
{
    return floor( value + 0.5f );
}

void BresenhamePlotter::DrawLineOnSceneWithDelegate( 
                const Line& line,
                IScene* scene )
{
    if ( line.IsPoint() )
    {
        scene->SetPixelXY( line.StartPoint().GetX(), line.StartPoint().GetY() );
        return;
    }
    else if ( line.IsHorizontal() )
    {
        DrawHorizontalLine( 
            line.StartPoint().GetX(), line.EndPoint().GetX(), 
            line.StartPoint().GetY(),
            scene );
        return;
    }
    else if ( line.IsVertical() )
    {
        DrawVerticalLine( 
            line.StartPoint().GetY(), line.EndPoint().GetY(), 
            line.StartPoint().GetX(),
            scene );
        return;
    }

    //TODO : optimize for integers usage
    float x = line.StartPoint().GetX();
    float y = line.StartPoint().GetY();

    float dx = 0.f;
    float dy = 0.f;
    CoordinateType length = 0;

    CoordinateType xLength = line.LengthX();
    CoordinateType yLength = line.LengthY();
    
    

    if ( xLength > yLength )
    {
        dx = 1.f * line.OrtX();
        dy = (float)yLength / (float)xLength * line.OrtY();
        length = xLength;
    }
    else
    {
        dx = (float)xLength / (float)yLength * line.OrtX();
        dy = 1.f * line.OrtY();
        length = yLength;
    }

    for ( CoordinateType i = 0; i <= length; ++i )
    {
        scene->SetPixelXY( 
            static_cast<CoordinateType>( round( x ) ), 
            static_cast<CoordinateType>( round( y ) ) );

        x += dx;
        y += dy;
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
 
