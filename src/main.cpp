#include "ClassInfo.h"
#include "CBInputProcessor.h"
#include "CBOutputProcessor.h"
#include "FileUtils.h"
#include "DirectoryUtils.h"
#include "TemplateChecker.h"

using namespace fe;
using namespace std;

bool CheckTemplates(int argc, char** argv, string& headerTpl, string& sourceTpl)
{
	if (argc != 1 && argc != 3)
	{
		cerr << "usage: cbuilder [headerTpl] [sourceTpl]" << endl;
		return false;
	}

	if (argc == 3 && !TemplateChecker::ExtractFromArgs(argv, headerTpl, sourceTpl))
	{
		cerr << "[ ERROR ] Some of the template files not found: " << argv[1] << " or " << argv[2] << endl;
		return false;
	}
	
	if (argc == 1 && !TemplateChecker::ExtractFromHome(headerTpl, sourceTpl))
	{
		cerr << "[ ERROR ] Missing default template files. Did you make: $ make install?" << endl;
		return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	string headerTpl(""), sourceTpl("");

	if (!CheckTemplates(argc, argv, headerTpl, sourceTpl))
		return 1;

	cout << "Using header template: " << headerTpl << endl;
	cout << "Using source template: " << sourceTpl << endl;

	ClassInfo cInfo;
	CBInputProcessor iProcessor;
	CBOutputProcessor oProcessor;

	iProcessor.processInput(cInfo);
	oProcessor.processOutput(cInfo, headerTpl, sourceTpl);

	return 0;
}
