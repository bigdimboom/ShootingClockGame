// the null object to prevent null tickable
#pragma once
#include "itickable.h"

namespace hcts
{

class NullTickable : public hcts::ITickable
{
private:
	// CONSTRUCTORS
	NullTickable();
	// default constructor.
	NullTickable(const NullTickable &) = delete;
	// copy constructor.
	NullTickable(NullTickable &&) = delete;
	// move constructor.

	~NullTickable();

	// OPERATOR OVERLOADS
	NullTickable& operator =(const NullTickable &) = delete;
	// copy assignment.
	NullTickable& operator =(NullTickable &&) = delete;
	// move assignment.
public:
	// ACCESSORS
	static NullTickable& inst();

	void preTick();
	void tick();
	void postTick();
};

} // end namespace hcts

