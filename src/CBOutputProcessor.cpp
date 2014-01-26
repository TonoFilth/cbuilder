#include "CBOutputProcessor.h"
#include "FileUtils.h"

namespace fe
{

// =============================================================================
//	CONSTANTS
// =============================================================================
const string K_HEADER_GUARD = "__GUARD";
const string K_HEADER_NAME  = "__HEADER";
const string K_NS_START  	= "__NAMESPACE-START";
const string K_NS_END		= "__NAMESPACE-END";
const string K_CLASS_NAME   = "__CLASS";

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
CBOutputProcessor::CBOutputProcessor()
{
}

CBOutputProcessor::~CBOutputProcessor()
{
}

// =============================================================================
//	PRIVATE AND PROTECTED METHODS
// =============================================================================
string CBOutputProcessor::__parseFileContents(const string& fileContents)
{
	string parsedFileContents(fileContents);

	for(auto& kv : m_ReplaceMap)
	{
		size_t lastPos = parsedFileContents.find(kv.first, 0);

		while(lastPos != string::npos)
		{
			parsedFileContents.replace(lastPos, kv.first.size(), kv.second);
			lastPos = parsedFileContents.find(kv.first, lastPos + 1);
		}
	}

	return parsedFileContents;
}

void CBOutputProcessor::__generateReplaceMap(const ClassInfo& cInfo)
{
	m_ReplaceMap[K_HEADER_GUARD] = cInfo.getHeaderGuard();
	m_ReplaceMap[K_NS_START] = "namespace " + cInfo.getNamespace() + "\n{";
	m_ReplaceMap[K_NS_END] = "}";
	m_ReplaceMap[K_CLASS_NAME] = cInfo.getClassName();
}

// =============================================================================
//	REGULAR METHODS
// =============================================================================
bool CBOutputProcessor::processOutput(ClassInfo& cInfo, const string& tplHeader, const string& tplSource)
{
	return processOutput(cInfo, tplHeader, tplSource, "", "");
}

bool CBOutputProcessor::processOutput(ClassInfo& cInfo, const string& tplHeader, const string& tplSource,
		const string& headerOutputFileName, const string& sourceOutputFileName)
{
	string tplHeaderContents;
	string tplSourceContents;
	string hOutFileName(headerOutputFileName);
	string sOutFileName(sourceOutputFileName);

	if(hOutFileName == "") hOutFileName = cInfo.getClassName() + ".h";
	if(sOutFileName == "") sOutFileName = cInfo.getClassName() + ".cpp";

	if(!FileUtils::FileToString(tplHeader, tplHeaderContents)) return false;
	if(!FileUtils::FileToString(tplSource, tplSourceContents)) return false;

	__generateReplaceMap(cInfo);

	if(!FileUtils::StringToFile(__parseFileContents(tplHeaderContents), hOutFileName)) return false;
	if(!FileUtils::StringToFile(__parseFileContents(tplSourceContents), sOutFileName)) return false;

	return true;
}

}