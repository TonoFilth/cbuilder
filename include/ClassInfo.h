#ifndef __CLASS_INFO_H__
#define __CLASS_INFO_H__

#include <string>

using namespace std;

namespace fe
{

class ClassInfo
{
private:
	string m_HeaderGuard;
	string m_Namespace;
	string m_ClassName;

public:
	ClassInfo();
	ClassInfo(const ClassInfo& toCopy);
	ClassInfo& operator=(const ClassInfo& toCopy);
	~ClassInfo();

	const string& getHeaderGuard() const;
	const string& getNamespace() const;
	const string& getClassName() const;

	void setHeaderGuard(const string& headerGuard);
	void setNamespace(const string& ns);
	void setClassName(const string& className);
};

}

#endif