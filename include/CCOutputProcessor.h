#ifndef __CC_OUTPUT_PROCESSOR_H__
#define __CC_OUTPUT_PROCESSOR_H__

#include <string>
#include "ClassInfo.h"

using namespace std;

namespace fe
{

class CCOutputProcessor
{
public:
	CCOutputProcessor();
	CCOutputProcessor(const CCOutputProcessor& toCopy);
	CCOutputProcessor& operator=(const CCOutputProcessor& toCopy);
	virtual ~CCOutputProcessor();

	bool processOutput(ClassInfo& cInfo);
};

}

#endif