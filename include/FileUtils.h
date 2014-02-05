#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__

#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

namespace fe
{

class FileUtils
{
public:
	FileUtils();
	FileUtils(const FileUtils& toCopy);
	FileUtils& operator=(const FileUtils& toCopy);
	~FileUtils();

	static bool FileToString(const string& fileName, string& toSave);
	static bool StringToFile(const string& stringToWrite, const string& fileName);

	static bool Exists(const string& fileName);
};

}

#endif