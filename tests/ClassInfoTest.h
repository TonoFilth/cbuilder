#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ClassInfo.h"

using namespace CppUnit;

namespace fe
{

class ClassInfoTest : public TestFixture
{
	CPPUNIT_TEST_SUITE(ClassInfoTest);
	CPPUNIT_TEST(testEmptyClassInfo);
	CPPUNIT_TEST(testGettersSetters);
	CPPUNIT_TEST_SUITE_END();

private:
	ClassInfo* m_ClassInfo;

public:
	virtual void setUp();
	virtual void tearDown();

	void testEmptyClassInfo();
	void testGettersSetters();
};

}