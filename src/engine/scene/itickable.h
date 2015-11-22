// itickable.h
#pragma once

namespace hcts
{

class ITickable
{
public:
	virtual ~ITickable(){}
	virtual void preTick() = 0;
	virtual void tick() = 0;
	virtual void postTick() = 0;
};

} // end namespace sgds

