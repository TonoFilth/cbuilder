#ifndef __CB_OUTPUT_PROCESSOR_H__
#define __CB_OUTPUT_PROCESSOR_H__

#include <map>
#include <string>

#include "ClassInfo.h"

using namespace std;

namespace fe
{

typedef map<string, string> StringMap;

class CBOutputProcessor
{
private:
	StringMap m_ReplaceMap;

	void __generateReplaceMap(const ClassInfo& cInfo);
	string __parseFileContents(const string& fileContents);

public:
	CBOutputProcessor();
	CBOutputProcessor(const CBOutputProcessor& toCopy);
	CBOutputProcessor& operator=(const CBOutputProcessor& toCopy);
	virtual ~CBOutputProcessor();

	bool processOutput(ClassInfo& cInfo, const string& tplHeader, const string& tplSource);
	bool processOutput(ClassInfo& cInfo, const string& tplHeader, const string& tplSource,
		const string& headerOutputFileName, const string& sourceOutputFileName);
};

}

#endif