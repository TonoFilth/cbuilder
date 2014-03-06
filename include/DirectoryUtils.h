#ifndef __DIRECTORY_UTILS_H__
#define __DIRECTORY_UTILS_H__

#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

using namespace std;

namespace fe
{

class DirectoryUtils
{
public:
	DirectoryUtils();
	DirectoryUtils(const DirectoryUtils& toCopy);
	DirectoryUtils& operator=(const DirectoryUtils& toCopy);
	~DirectoryUtils();

	static string GetUserHomeDir();
};

}

#endif
