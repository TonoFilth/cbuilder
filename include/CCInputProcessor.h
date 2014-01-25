#ifndef __CC_INPUT_PROCESSOR_H__
#define __CC_INPUT_PROCESSOR_H__

#include <string>
#include "ClassInfo.h"

using namespace std;

namespace fe
{

class CCInputProcessor
{
public:
	CCInputProcessor();
	CCInputProcessor(const CCInputProcessor& toCopy);
	CCInputProcessor& operator=(const CCInputProcessor& toCopy);
	virtual ~CCInputProcessor();

	bool processInput(ClassInfo& cInfo, const string& tplHeader, const string& tplSource);
};

}

#endif