#include <iostream>
#include <fstream>

#include "FileUtils.h"

namespace fe
{

// =============================================================================
//	STATIC METHODS
// =============================================================================
bool FileUtils::FileToString(const string& fileName, string& toSave)
{
	ifstream file(fileName.c_str());

	if(!file.is_open())
	{
		cerr << "Error opening " << fileName << endl;
		return false;
	}

	string readLine;

	while(getline(file, readLine))
		toSave += readLine + "\n";

	file.close();
	
	return true;
}

bool FileUtils::StringToFile(const string& stringToWrite, const string& fileName)
{
	ofstream file(fileName.c_str());

	if(!file.is_open())
	{
		cerr << "Error opening file " << fileName << endl;
		return false;
	}

	file << stringToWrite;

	file.close();
	return true;
}

}