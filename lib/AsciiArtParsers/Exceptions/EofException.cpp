#include "StdAfx.h"
#include "EofException.h"

using namespace AsciiArt::Exceptions;

EofException::EofException():
    std::runtime_error( "Unexpected EOF encountered" )
{
}

EofException::EofException(const std::string& message ) :
    std::runtime_error( message )
{
}

EofException::~EofException(void) throw()
{
}
