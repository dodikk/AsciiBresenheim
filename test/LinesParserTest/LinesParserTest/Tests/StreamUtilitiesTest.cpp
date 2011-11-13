#include "StdAfx.h"
#include "StreamUtilitiesTest.h"

using namespace AsciiArt::Parser;
using namespace AsciiArt::Exceptions;

StreamUtilitiesTest::StreamUtilitiesTest(void)
{
}

StreamUtilitiesTest::~StreamUtilitiesTest(void)
{
}

void StreamUtilitiesTest::TestWhitespacesFunctionReturnsFalseForEmptyString()
{
    CPPUNIT_ASSERT( !StreamUtilities::StringContainsNotJustWhitespaces( "" ) );
    CPPUNIT_ASSERT_NO_THROW( StreamUtilities::AssertWhitespaceString( "" ) );
}

void StreamUtilitiesTest::TestWhitespacesFunctionReturnsValidResult()
{
    {
        CPPUNIT_ASSERT( !StreamUtilities::StringContainsNotJustWhitespaces( "  \n \t \r" ) );
        CPPUNIT_ASSERT_NO_THROW( StreamUtilities::AssertWhitespaceString( "  \n \t \r" ) );
    }

    {
        CPPUNIT_ASSERT( StreamUtilities::StringContainsNotJustWhitespaces( "  \n ala \t \r" ) );
        CPPUNIT_ASSERT_THROW
        ( 
            StreamUtilities::AssertWhitespaceString( "  \n 13 \t \r" ),
            UnexpectedFormatException
        );
    }
}
