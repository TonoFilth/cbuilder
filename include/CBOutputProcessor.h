#ifndef CB_OUTPUT_PROCESSOR_H
#define CB_OUTPUT_PROCESSOR_H

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

	void generateReplaceMap(const ClassInfo& cInfo);
	string parseFileContents(const string& fileContents);

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