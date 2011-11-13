#include "StdAfx.h"
#include "UnexpectedFormatException.h"

using namespace AsciiArt::Exceptions;

UnexpectedFormatException::UnexpectedFormatException() :
    std::runtime_error( "Parser failre - unexpected format" )
{
}

UnexpectedFormatException::UnexpectedFormatException(const std::string& message ) :
    std::runtime_error( message )
{
}

UnexpectedFormatException::~UnexpectedFormatException(void) throw()
{
}
