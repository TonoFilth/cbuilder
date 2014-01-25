#ifndef __CLASS_CREATOR_H__
#define __CLASS_CREATOR_H__

#include <string>

using namespace std;

namespace fe
{

class ClassCreator
{
private:

public:
	ClassCreator();
	ClassCreator(const ClassCreator& toCopy);
	ClassCreator& operator=(const ClassCreator& toCopy);
	~ClassCreator();
};

}

#endif