#include "StdAfx.h"
#include "UnexpectedFormatException.h"

using namespace AsciiArt::Exceptions;

UnexpectedFormatException::UnexpectedFormatException() :
    std::runtime_error( "" )
{
}

UnexpectedFormatException::UnexpectedFormatException(const std::string& message ) :
    std::runtime_error( message )
{
}

UnexpectedFormatException::~UnexpectedFormatException(void) throw()
{
}
