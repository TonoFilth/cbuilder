#ifndef __CB_INPUT_PROCESSOR_H__
#define __CB_INPUT_PROCESSOR_H__

#include <string>

#include "ClassInfo.h"
#include "InputProcessor.h"

using namespace std;

namespace fe
{

class CBInputProcessor
{
private:
	string m_HeaderGuardPrefix;
	string m_HeaderGuardSuffix;

	InputProcessor m_InputProcessor;

public:
	CBInputProcessor();
	CBInputProcessor(const CBInputProcessor& toCopy);
	CBInputProcessor& operator=(const CBInputProcessor& toCopy);
	virtual ~CBInputProcessor();

	void setHeaderGuardPrefix(const string& prefix);
	void setHeaderGuardSuffix(const string& suffix);
	void setHeaderGuardAffixes(const string& prefix, const string& suffix);

	bool processInput(ClassInfo& cInfo);
};

}

#endif