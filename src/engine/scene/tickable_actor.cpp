// tickable_actor.cpp
#include "tickable_actor.h"
#include "../events/event_bus.h"

namespace hcts
{

// CONSTRUCTORS
TickableActor::TickableActor(hctm::Point2f position, hctm::Point2f velocity)
	: Actor(position)
	, d_vel(velocity)
{
}

TickableActor::TickableActor(const TickableActor & o)
	: Actor(o.d_pos)
	, d_vel(o.d_vel)
{
}

TickableActor::TickableActor(TickableActor && o)
	: Actor(std::move(o.d_pos))
	, d_vel(std::move(o.d_vel))
{
}

// ASSIGNMENT OVERLOADS
TickableActor& TickableActor::operator = (const TickableActor & o)
{
	if (this != &o)
	{
		d_pos = o.d_pos;
		d_vel = o.d_vel;
	}
	return *this;
}

TickableActor& TickableActor::operator = (TickableActor && o)
{
	if (this != &o)
	{
		d_pos = std::move(o.d_pos);
		d_vel = std::move(o.d_vel);
	}
	return *this;
}

// DESTRUCTOR
TickableActor::~TickableActor()
{
}

// ACCESSORS
hctm::Point2f TickableActor::velocity() const
{
	return d_vel;
}

// MUTATORS
void TickableActor::setVelocity(hctm::Point2f vel)
{
	d_vel = vel;
}

void TickableActor::addToVelocity(hctm::Point2f deltaV)
{
	d_vel += deltaV;
}


// MEMBER FUNCTIONS
void TickableActor::preTick()
{
}

void TickableActor::tick()
{
	d_pos += d_vel;
}

} // end namespace hcts