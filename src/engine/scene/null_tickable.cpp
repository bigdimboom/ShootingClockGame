// null_tickable.cpp
#include "null_tickable.h"

namespace hcts
{
NullTickable::NullTickable()
{

}

NullTickable::~NullTickable()
{

}

NullTickable& NullTickable::inst()
{
	static NullTickable inst;
	return inst;
}

void NullTickable::preTick()
{
}

void NullTickable::tick()
{
}

void NullTickable::postTick()
{
}

}