#include "StdAfx.h"
#include "LinesParserTest.h"

using namespace AsciiArt::Parser;
using namespace AsciiArt::Core;
using namespace AsciiArt::Exceptions;

LinesParserTest::LinesParserTest(void)
{
}

LinesParserTest::~LinesParserTest(void)
{
}



void LinesParserTest::TestEmptyStreamProducesEmptyPoints()
{
    std::string TestData;
    std::stringstream linesStream( TestData );

    LinesParser parser;
    Lines_vt received;
    parser.ParseLines( linesStream, received );

    CPPUNIT_ASSERT( received.empty() );
}


void LinesParserTest::TestPointsParsedCorrectly()
{
    std::ifstream linesStream( "../LinesParserTest/TestData/1-Valid3Points.txt" );

    LinesParser parser;
    Lines_vt received;
    parser.ParseLines( linesStream, received );

    CPPUNIT_ASSERT( 3 == received.size() );

    {
        const Line& line = received.at(0);
        CPPUNIT_ASSERT( line.StartPoint().GetX() == 1 );
        CPPUNIT_ASSERT( line.StartPoint().GetY() == 2 );

        CPPUNIT_ASSERT( line.EndPoint().GetX() == 3 );
        CPPUNIT_ASSERT( line.EndPoint().GetY() == 4 );
    }

    {
        const Line& line = received.at(1);
        CPPUNIT_ASSERT( line.StartPoint().GetX() == 5 );
        CPPUNIT_ASSERT( line.StartPoint().GetY() == 6 );

        CPPUNIT_ASSERT( line.EndPoint().GetX() == 7 );
        CPPUNIT_ASSERT( line.EndPoint().GetY() == 8 );
    }

    {
        const Line& line = received.at(2);
        CPPUNIT_ASSERT( line.StartPoint().GetX() == 9 );
        CPPUNIT_ASSERT( line.StartPoint().GetY() == 10 );

        CPPUNIT_ASSERT( line.EndPoint().GetX() == 11 );
        CPPUNIT_ASSERT( line.EndPoint().GetY() == 12 );
    }
}


void LinesParserTest::TestInvalidCharactersAfterCoordinatesProduceCrash()
{
    std::ifstream linesStream( "../LinesParserTest/TestData/2-LettersAfterNumber.txt" );

    LinesParser parser;
    Lines_vt received;

    CPPUNIT_ASSERT_THROW
        (
        parser.ParseLines( linesStream, received ),
        UnexpectedFormatException
        );
}


void LinesParserTest::TestInvalidCharactersBeforeCoordinatesProduceCrash()
{
    {
        std::ifstream linesStream( "../LinesParserTest/TestData/3-LettersBeforeNumber.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
        (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
        );
    }
}


void LinesParserTest::TestInvalidCharactersBetweenSeparatorsProduceCrash()
{
    {
        std::ifstream linesStream( "../LinesParserTest/TestData/3-LettersBeforeNumber.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/4-LettersBeforeBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/5-LettersAfterBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/6-LettersBeforeBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }


    {
        std::ifstream linesStream( "../LinesParserTest/TestData/7-LettersAfterBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }
}


void LinesParserTest::TestMissingSeparatorsProduceCrash()
{
    {
        std::ifstream linesStream( "../LinesParserTest/TestData/8-NoOpenBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/9-NoOpenBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/10-NoCloseBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
            (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
            );
    }


    {
        std::ifstream linesStream( "../LinesParserTest/TestData/12-NoLine.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
        (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
        );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/13-NoCloseBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
        (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
        );
    }

        {
        std::ifstream linesStream( "../LinesParserTest/TestData/15-NoPointComa.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
        (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
        );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/16-NoSeparatorComa.txt" );

        LinesParser parser;
        Lines_vt received;

        CPPUNIT_ASSERT_THROW
        (
            parser.ParseLines( linesStream, received ),
            UnexpectedFormatException
        );
    }

}

void LinesParserTest::TestUnexpectedSymbolsAtTheEndSkippedQuietly()
{
    {
        std::ifstream linesStream( "../LinesParserTest/TestData/11-NoCloseBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        parser.ParseLines( linesStream, received );
        CPPUNIT_ASSERT( received.empty() );
    }

    {
        std::ifstream linesStream( "../LinesParserTest/TestData/14-NoCloseBracket.txt" );

        LinesParser parser;
        Lines_vt received;

        parser.ParseLines( linesStream, received );
        CPPUNIT_ASSERT( 2 == received.size() );
    }
}
