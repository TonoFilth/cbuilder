#include "CBInputProcessor.h"

namespace fe
{

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
CBInputProcessor::CBInputProcessor() :
	m_HeaderGuardPrefix(""),
	m_HeaderGuardSuffix("_HPP")
{
}

CBInputProcessor::~CBInputProcessor()
{
}

// =============================================================================
//	REGULAR METHODS
// =============================================================================
bool CBInputProcessor::processInput(ClassInfo& cInfo)
{
	string input;

	m_InputProcessor.read("Class Name", input);
	cInfo.setClassName(input);
	m_InputProcessor.read("Namespace", input);
	cInfo.setNamespace(input);
	m_InputProcessor.read("Header Guard", input);
	cInfo.setHeaderGuard(m_HeaderGuardPrefix + input + m_HeaderGuardSuffix);

	return true;
}

// =============================================================================
//	GETTERS & SETTERS
// =============================================================================
void CBInputProcessor::setHeaderGuardPrefix(const string& prefix)
{
	m_HeaderGuardPrefix = prefix;
}

void CBInputProcessor::setHeaderGuardSuffix(const string& suffix)
{
	m_HeaderGuardSuffix = suffix;
}

void CBInputProcessor::setHeaderGuardAffixes(const string& prefix, const string& suffix)
{
	setHeaderGuardPrefix(prefix);
	setHeaderGuardSuffix(suffix);
}

}