// actor.cpp
#include "actor.h"

namespace hcts
{
//COSTRUCTOS
Actor::Actor(hctm::Point2f pos)
	:d_pos(pos)
{
}

Actor::Actor(const Actor & actor)
	: d_pos(actor.d_pos)
{
}

Actor::Actor(Actor && actor)
	: d_pos(std::move(actor.d_pos))
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

//MUTATORS
void Actor::setPosition(hctm::Point2f pos)
{
	d_pos = pos;
}

void Actor::translate(hctm::Point2f deltaPos)
{
	d_pos += deltaPos;
}

} // end namespace hcts