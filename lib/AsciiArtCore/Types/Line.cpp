#include "StdAfx.h"
#include "Line.h"

using namespace AsciiArt::Core;

Line::Line()
{
}

Line::Line( const Point& start, const Point& end ) :
    start_( start ),
    end_  ( end   )
{
}

Line::~Line(void)
{
}


void Line::SetStartPoint( const Point& value )
{
    start_ = value;
}

void Line::SetEndPoint( const Point& value )
{
    end_ = value;
}

const Point& Line::StartPoint() const
{
    return start_;
}

const Point& Line::EndPoint() const
{
    return end_;
}

bool Line::IsHorizontal() const
{
    return start_.GetY() == end_.GetY();
}

bool Line::IsVertical() const
{
    return start_.GetX() == end_.GetX();
}

bool Line::IsPoint() const
{
    return IsHorizontal() && IsVertical();
}

CoordinateType Line::LengthX() const
{
    return abs( start_.GetX() - end_.GetX() );
}

CoordinateType Line::LengthY() const
{
    return abs( start_.GetY() - end_.GetY() );
}


static CoordinateType sign( CoordinateType value )
{
    if ( 0 == value )
    {
        return 0;
    }

    return ( value > 0) ? 1 : -1;
}

CoordinateType Line::OrtX() const
{
    return sign( end_.GetX() - start_.GetX() );
}

CoordinateType Line::OrtY() const
{
    return sign( end_.GetY() - start_.GetY() );
}


