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
