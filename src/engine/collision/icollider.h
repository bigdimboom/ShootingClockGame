// icollider.h
#pragma once
#include "aabb.h"

namespace hctc
{

enum CollisionType
{
	// TODO: 
};

class ICollider
{
public:
	virtual ~ICollider(){}
	virtual const Aabb& bounds() const = 0;
	virtual unsigned short flags() const = 0;
	virtual void setFlags(unsigned short flags) = 0;
	virtual bool canCollide(unsigned short flags) const = 0;
	virtual bool doesCollide(const Aabb & candidate) = 0;
};

} // end namespace hctc