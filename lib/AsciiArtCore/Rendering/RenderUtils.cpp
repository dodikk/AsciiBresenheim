#include "StdAfx.h"
#include "RenderUtils.h"

#include <AsciiArtCore/Exceptions/RangeException.h>

using namespace AsciiArt::Core;
using namespace AsciiArt::Exceptions;
using namespace AsciiArt::Rendering;

uchar RenderUtils::NextRenderSymbol( uchar renderSymbol )
{
    if ( '*' == renderSymbol )
    {
        return 'A';
    }
    else if ( 'Z' == renderSymbol )
    {
        return 'A';
    }

    ++renderSymbol;
    return renderSymbol;
}


bool RenderUtils::PointInRange( 
    const Point& point, 
    CoordinateType xMin, CoordinateType xMax, 
    CoordinateType yMin, CoordinateType yMax )
{
    return 
        ( point.GetX() >= xMin ) &&
        ( point.GetX() <= xMax ) &&
        ( point.GetY() >= yMin ) &&
        ( point.GetY() <= yMax ) ;
}

void RenderUtils::AssertPointInRange( 
    const Point& point, 
    CoordinateType xMin, CoordinateType xMax, 
    CoordinateType yMin, CoordinateType yMax )
{
    if ( !RenderUtils::PointInRange( point, xMin, xMax, yMin, yMax ) )
    {
        RangeException ex( point, xMin, xMax, yMin, yMax );
        throw ex;
    }
}


void RenderUtils::AssertLineInRange( 
                const Line& line, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax )
{
    RenderUtils::AssertPointInRange( line.StartPoint(), xMin, xMax, yMin, yMax );
    RenderUtils::AssertPointInRange( line.EndPoint  (), xMin, xMax, yMin, yMax );
}