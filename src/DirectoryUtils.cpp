#include "DirectoryUtils.h"

namespace fe
{

// =============================================================================
//	STATIC METHODS
// =============================================================================
string DirectoryUtils::GetUserHomeDir()
{
	struct passwd *pw = getpwuid(getuid());
	return string(pw->pw_dir);
}

}
