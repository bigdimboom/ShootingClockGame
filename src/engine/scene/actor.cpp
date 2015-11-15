// actor.cpp
#include "actor.h"

namespace hcts
{
//COSTRUCTOS
Actor::Actor(hctm::Point2f pos, hctm::Point2f vel)
	:d_pos(pos)
{
}

Actor::Actor(const Actor & actor)
	: d_pos(actor.d_pos)
	, d_vel(actor.d_vel)
{
}

Actor::Actor(Actor && actor)
	: d_pos(std::move(actor.d_pos))
	, d_vel(std::move(actor.d_vel))
{
}

// ASSIGNMENT OVERLOADS
Actor& Actor::operator = (const Actor & other)
{
	if (this != &other)
	{
		d_pos = other.d_pos;
	}
	return *this;
}

Actor& Actor::operator = (Actor && other)
{
	if (this != &other)
	{
		d_pos = std::move(other.d_pos);
	}
	return *this;
}

//DESTRUCTOR
Actor::~Actor()
{
}

//ACCESSORS
hctm::Point2f Actor::positionXY() const
{
	return d_pos;
}

hctm::Point2f Actor::velocityXY() const
{
	return d_vel;
}

//MUTATORS
void Actor::set(hctm::Point2f pos)
{
	d_pos = pos;
}

void Actor::translate(hctm::Point2f deltaPos)
{
	d_pos += deltaPos;
}

void Actor::setSpeed(hctm::Point2f velocity)
{
	d_vel += velocity;
}

} // end namespace hcts