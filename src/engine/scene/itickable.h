// itickable.h
#pragma once

namespace hcts
{

class ITickable
{
public:
	~ITickable(){}
	virtual void preTick() = 0;
	virtual void tick() = 0;
};

} // end namespace sgds

