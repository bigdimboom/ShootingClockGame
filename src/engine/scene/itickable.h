// itickable.h
#pragma once

namespace hcts
{

class ITickable
{
public:
	virtual ~ITickable(){}
	virtual void tick(float dtime) = 0;
};

} // end namespace sgds

