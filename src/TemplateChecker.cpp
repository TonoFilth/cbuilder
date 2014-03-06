#include "TemplateChecker.h"

namespace fe
{

// =============================================================================
//	CONSTANTS
// =============================================================================
const string K_TEMPLATE_DIR   	   = ".cbuilder/templates/";
const string K_DEF_HEADER_TPL_NAME = "DefHeader.tpl";
const string K_DEF_SOURCE_TPL_NAME = "DefSource.tpl";

const string TemplateChecker::K_HOME_DIR = DirectoryUtils::GetUserHomeDir();
const string TemplateChecker::K_DEF_HEADER_TPL = K_HOME_DIR + "/" + K_TEMPLATE_DIR + K_DEF_HEADER_TPL_NAME;
const string TemplateChecker::K_DEF_SOURCE_TPL = K_HOME_DIR + "/" + K_TEMPLATE_DIR + K_DEF_SOURCE_TPL_NAME;

// =============================================================================
//	REGULAR METHODS
// =============================================================================
bool TemplateChecker::ExtractFromArgs(char** argv, string& headerTpl, string& sourceTpl)
{
	if (!FileUtils::Exists(string(argv[1])) || !FileUtils::Exists(string(argv[2])))
		return false;

	headerTpl = argv[1];
	sourceTpl = argv[2];

	return true;
}

bool TemplateChecker::ExtractFromHome(string& headerTpl, string& sourceTpl)
{
	if (!FileUtils::Exists(K_DEF_HEADER_TPL))
		return false;
	
	if (!FileUtils::Exists(K_DEF_SOURCE_TPL))
		return false;

	headerTpl = K_DEF_HEADER_TPL;
	sourceTpl = K_DEF_SOURCE_TPL;

	return true;
}

}
