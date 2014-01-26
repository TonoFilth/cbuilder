#include "ClassInfo.h"
#include "CBInputProcessor.h"
#include "CBOutputProcessor.h"

using namespace fe;
using namespace std;

int main(int argc, char** argv)
{
	ClassInfo cInfo;
	CBInputProcessor iProcessor;
	CBOutputProcessor oProcessor;

	iProcessor.processInput(cInfo);
	oProcessor.processOutput(cInfo, "templates/template.h", "templates/template.cpp");

	return 0;
}
