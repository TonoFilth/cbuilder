#include <string>
#include "ClassInfoTest.h"

using namespace std;
using namespace CppUnit;

namespace fe
{

// =============================================================================
//	TEST STARTUP / TEARDOWN
// =============================================================================
void ClassInfoTest::setUp()
{
	m_ClassInfo = new ClassInfo();
}

void ClassInfoTest::tearDown()
{
	if(m_ClassInfo != nullptr)
		delete m_ClassInfo;
}

// =============================================================================
//	TEST CASES
// =============================================================================
void ClassInfoTest::testEmptyClassInfo()
{
	CPPUNIT_ASSERT(m_ClassInfo->getHeaderGuard() == "");
	CPPUNIT_ASSERT(m_ClassInfo->getNamespace() == "");
	CPPUNIT_ASSERT(m_ClassInfo->getClassName() == "");
}

void ClassInfoTest::testGettersSetters()
{
	const string headerGuard = "TestHeaderGuard";
	const string ns 		 = "TestNamespace";
	const string className   = "TestClass";

	m_ClassInfo->setHeaderGuard(headerGuard);
	m_ClassInfo->setNamespace(ns);
	m_ClassInfo->setClassName(className);

	CPPUNIT_ASSERT(m_ClassInfo->getHeaderGuard() == headerGuard);
	CPPUNIT_ASSERT(m_ClassInfo->getNamespace() == ns);
	CPPUNIT_ASSERT(m_ClassInfo->getClassName() == className);
}

}