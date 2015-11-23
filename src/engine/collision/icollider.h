// icollider.h
#pragma once
#include "aabb.h"

namespace hctc
{


// HOW TO USE IT:
// SET (OTHERS | DYNAMIC_COLLIDER)
// if( (OTHERS & DYNAMIC_COLLIDER) == DYNAMIC_COLLIDER)

// MAKE IT SATIC

#define DYNAMIC_COLLIDER 0x0001 // 0000001

// fist digit of these bit must be 0;
#define STATIC_COLLIDER   0x0000
#define WALL_COLLIDER     0x0002 // 000010
#define BULLET_COLLIDER   0x0004 // 000100
#define BULLET_HIT        0x0008 // 001000
#define HIT_BY_BULLET     0x0010 // 010000
#define CLOCK_COLLIDER    0x0020 // 100000

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