#ifndef TEMPLATE_CHECKER_H
#define TEMPLATE_CHECKER_H

#include <iostream>

#include "FileUtils.h"
#include "DirectoryUtils.h"

namespace fe
{

class TemplateChecker
{
private:
	static const string K_HOME_DIR;
	static const string K_DEF_HEADER_TPL;
	static const string K_DEF_SOURCE_TPL;

public:
	TemplateChecker();
	TemplateChecker(const TemplateChecker& toCopy);
	TemplateChecker& operator=(const TemplateChecker& toCopy);
	~TemplateChecker();

	static bool ExtractFromArgs(char** argv, string& headerTpl, string& sourceTpl);
	static bool ExtractFromHome(string& headerTpl, string& sourceTpl);
};

}

#endif
