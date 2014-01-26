#include "InputProcessor.h"

namespace fe
{

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
InputProcessor::InputProcessor() :
	m_QuestionPrefix(""),
	m_QuestionSuffix(": ")
{
}

InputProcessor::~InputProcessor()
{
}

// =============================================================================
//	REGULAR METHODS
// =============================================================================

// =============================================================================
//	GETTERS & SETTERS
// =============================================================================
void InputProcessor::setQuestionPrefix(const string& prefix)
{
	m_QuestionPrefix = prefix;
}

void InputProcessor::setQuestionSuffix(const string& suffix)
{
	m_QuestionSuffix = suffix;
}

}
