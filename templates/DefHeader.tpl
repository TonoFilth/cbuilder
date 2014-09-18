#ifndef __GUARD
#define __GUARD

__NAMESPACE-START

/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// /////////////////////////////////////////////////////////////////////////////
//                                __CLASS
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// ///////////////////////////////////////////////////////////////////////////*/
class __CLASS
{
public:
	__CLASS();
	~__CLASS();

private:
	// Non-copyable
	__CLASS(const __CLASS& toCopy)            = delete;
	__CLASS& operator=(const __CLASS& toCopy) = delete;
};

__NAMESPACE-END

#endif	// __GUARD
