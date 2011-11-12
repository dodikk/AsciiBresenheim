#ifndef __LINES_PARSER_TEST_H__
#define __LINES_PARSER_TEST_H__

#include <cppunit/extensions/HelperMacros.h>

class LinesParserTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( LinesParserTest );
    CPPUNIT_TEST( TestEmptyStreamProducesEmptyPoints                 );
    CPPUNIT_TEST( TestPointsParsedCorrectly                          );
    CPPUNIT_TEST( TestInvalidCharactersAfterCoordinatesProduceCrash  );
    CPPUNIT_TEST( TestInvalidCharactersBeforeCoordinatesProduceCrash );
    CPPUNIT_TEST( TestInvalidCharactersBetweenSeparatorsProduceCrash );
    CPPUNIT_TEST( TestMissingSeparatorsProduceCrash                  );
    CPPUNIT_TEST( TestUnexpectedSymbolsAtTheEndSkippedQuietly        );
  CPPUNIT_TEST_SUITE_END();

public:
    void TestEmptyStreamProducesEmptyPoints                 ();
    void TestPointsParsedCorrectly                          ();
    void TestInvalidCharactersAfterCoordinatesProduceCrash  ();
    void TestInvalidCharactersBeforeCoordinatesProduceCrash ();
    void TestInvalidCharactersBetweenSeparatorsProduceCrash ();
    void TestMissingSeparatorsProduceCrash                  ();
    void TestUnexpectedSymbolsAtTheEndSkippedQuietly        ();

public:
    LinesParserTest(void);
    virtual ~LinesParserTest(void);
};


#endif //__LINES_PARSER_TEST_H__

