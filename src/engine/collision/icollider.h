// icollider.h
#pragma once
#include "aabb.h"

namespace hctc
{

enum class ColliderType
{
	// TODO: 
	UNSET,
	STATIC_COLLIDER,
	DYNAMIC_COLLIDER
};

class ICollider
{
public:
	virtual ~ICollider(){}
	virtual Aabb& bounds() = 0;
	virtual ColliderType flags() const = 0;
	virtual void setFlags(ColliderType flags) = 0;
	//virtual bool canCollide(unsigned short flags) const = 0;
	virtual bool doesCollide(const Aabb & candidate) = 0;
};

} // end namespace hctc