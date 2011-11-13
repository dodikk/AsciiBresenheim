#ifndef __STREAM_UTILITIES_TEST_H__
#define __STREAM_UTILITIES_TEST_H__

#include <cppunit/extensions/HelperMacros.h>

class StreamUtilitiesTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( StreamUtilitiesTest );
    CPPUNIT_TEST( TestWhitespacesFunctionReturnsFalseForEmptyString );
    CPPUNIT_TEST( TestWhitespacesFunctionReturnsValidResult         );
CPPUNIT_TEST_SUITE_END();

public:
    void TestWhitespacesFunctionReturnsFalseForEmptyString();
    void TestWhitespacesFunctionReturnsValidResult        ();

public:
    StreamUtilitiesTest(void);
    virtual ~StreamUtilitiesTest(void);
};

#endif //__STREAM_UTILITIES_TEST_H__
