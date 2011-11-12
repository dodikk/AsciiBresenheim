#include "StdAfx.h"
#include "Point.h"

using namespace AsciiArt::Core;

Point::Point(void)
{
}

Point::~Point(void)
{
}

void Point::SetX( CoordinateType value )
{
    x_ = value;
}

void Point::SetY( CoordinateType value )
{
    y_ = value;
}

CoordinateType Point::GetX() const
{
    return x_;
}

CoordinateType Point::GetY() const
{
    return y_;
}
