// icollider.h
#pragma once
#include "aabb.h"

namespace hctc
{


// HOW TO USE IT:
// SET (OTHERS | DYNAMIC_COLLIDER)
// if( (OTHERS & DYNAMIC_COLLIDER) == DYNAMIC_COLLIDER)

// MAKE IT SATIC

#define DYNAMIC_COLLIDER 0x0001 // 0001

// fist digit of these bit must be 0;
#define STATIC_COLLIDER   0x0000
#define RESERVE_COLLIDER1 0x0002 // 0010
#define RESERVE_COLLIDER2 0x0004 // 0100
#define RESERVE_COLLIDER3 0x0006 // 0110
#define RESERVE_COLLIDER4 0x0008 // 1000

class ICollider
{
public:
	virtual ~ICollider(){}
	virtual Aabb& bounds() = 0;
	virtual unsigned short flags() const = 0;
	virtual void setFlags(unsigned short flags) = 0;
	//virtual bool canCollide(unsigned short flags) const = 0;
	virtual bool doesCollide(const Aabb & candidate) = 0;
};

} // end namespace hctc