#include "StdAfx.h"
#include "StreamUtilities.h"

using namespace AsciiArt::Parser;
using namespace AsciiArt::Exceptions;

static char whitespacesCount = 33;
static char whitespaces[] = { 0 };

static void InitializeWhitespaces()
{
    bool whitespacesInitialized = (whitespaces[1] != 0);
    if ( !whitespacesInitialized )
    {
        for ( char i = 0; i < whitespacesCount; ++i )
        {
            whitespaces[i] = i;
        }
    }
}

bool StreamUtilities::StringContainsNotJustWhitespaces( const std::string& str )
{
    InitializeWhitespaces();
    static std::string whitespacesString( whitespaces, whitespaces + whitespacesCount );

    size_t foundIndex = str.find_first_not_of( whitespacesString );
    return ( std::string::npos != foundIndex );
}

void StreamUtilities::AssertWhitespaceString( const std::string& str )
{
    if ( StreamUtilities::StringContainsNotJustWhitespaces( str ) )
    {
        throw UnexpectedFormatException( str );
    }
}
