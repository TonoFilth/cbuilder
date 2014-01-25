#include "ClassInfo.h"

namespace fe
{

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
ClassInfo::ClassInfo() :
	m_HeaderGuard(""),
	m_Namespace(""),
	m_ClassName("")
{
}

ClassInfo::~ClassInfo()
{
	m_HeaderGuard = "";
	m_Namespace   = "";
	m_ClassName	  = "";
}

// =============================================================================
//	GETTERS & SETTERS
// =============================================================================
const string& ClassInfo::getHeaderGuard() const { return m_HeaderGuard; }
const string& ClassInfo::getNamespace() const 	{ return m_Namespace; }
const string& ClassInfo::getClassName() const 	{ return m_ClassName; }

void ClassInfo::setHeaderGuard(const string& headerGuard) { m_HeaderGuard = headerGuard; }
void ClassInfo::setNamespace(const string& ns) 			  { m_Namespace = ns; }
void ClassInfo::setClassName(const string& className) 	  { m_ClassName = className; }

}