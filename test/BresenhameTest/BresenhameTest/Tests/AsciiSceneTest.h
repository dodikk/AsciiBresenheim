#ifndef __ASCII_SCENE_TEST_H__
#define __ASCII_SCENE_TEST_H__

#include <cppunit/extensions/HelperMacros.h>

class AsciiSceneTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( AsciiSceneTest );
    CPPUNIT_TEST( TestEmptyArrayProducesEmptyScene        );
    CPPUNIT_TEST( TestSinglePointSegmentRenderedCorrectly );

    CPPUNIT_TEST( TestRangeViolationsProduceCrash         );

    CPPUNIT_TEST( TestHorizontalSegmentRenderedCorrectly  );
    CPPUNIT_TEST( TestVerticalSegmentRenderedCorrectly    );
    CPPUNIT_TEST( TestAverageSegmentRenderedCorrectly     );
    CPPUNIT_TEST( TestMultipleSegmentsRenderedCorrectly   );
CPPUNIT_TEST_SUITE_END();

public:
    void TestEmptyArrayProducesEmptyScene       ();
    void TestSinglePointSegmentRenderedCorrectly();
    void TestRangeViolationsProduceCrash        ();
    void TestHorizontalSegmentRenderedCorrectly ();
    void TestVerticalSegmentRenderedCorrectly   ();
    void TestAverageSegmentRenderedCorrectly    ();
    void TestMultipleSegmentsRenderedCorrectly  ();


public:
    AsciiSceneTest(void);
    virtual ~AsciiSceneTest(void);
};


#endif //__ASCII_SCENE_TEST_H__
