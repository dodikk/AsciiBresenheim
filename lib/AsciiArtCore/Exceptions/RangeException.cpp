#include "StdAfx.h"
#include "RangeException.h"

using namespace AsciiArt::Core;
using namespace AsciiArt::Exceptions;

std::string RangeException::CreateMessage( 
                const Point& point, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax  )
{   
    std::stringstream msgStream;
    msgStream << "Point [" << point.GetX() << " , " << point.GetY() << "]"
              << " exceeds the range : [" << xMin << ".." << xMax << "]"
              << " , " << "[" << yMin << ".." << yMax << "]";

    return msgStream.str();
}

RangeException::RangeException( 
    const Point& point, 
    CoordinateType xMin, CoordinateType xMax, 
    CoordinateType yMin, CoordinateType yMax  ) : 
std::runtime_error( RangeException::CreateMessage(point, xMin, xMax, yMin, yMax ) ) 
{
}

RangeException::~RangeException(void) throw()
{
}
