// pawn.cpp
#include "pawn.h"

namespace hctg
{

// CONSTRUCTOR
Pawn::Pawn(hctm::Point2f pos, hctm::Point2f vel)
	: Actor(pos)
	, d_vel(vel)
{
}

Pawn::Pawn(const Pawn & other)
	: Actor(other.d_pos)
	, d_vel(other.d_vel)
{
}

Pawn::Pawn(Pawn && other)
	: Actor(std::move(other.d_pos))
	, d_vel(std::move(other.d_vel))
{
}

// ASSIGNMENT OVERLOADS
Pawn& Pawn::operator = (const Pawn & other)
{
	if (this != &other)
	{
		d_pos = other.d_pos;
		d_vel = other.d_pos;
	}
	return *this;
}

Pawn& Pawn::operator = (Pawn && other)
{
	if (this != &other)
	{
		d_pos = std::move(other.d_pos);
		d_vel = std::move(other.d_pos);
	}
	return *this;
}

// DESTRUCTOR
Pawn::~Pawn()
{
}


// ACCESSOR 
hctm::Point2f Pawn::velocity() const
{
	return d_vel;
}

// MUTATOR
void Pawn::setVelocity(hctm::Point2f velocity)
{
	d_vel = velocity;
}

// MEMBER FUNCTIONS
void Pawn::preTick()
{
	//Do Nothing
}

void Pawn::tick()
{
	d_pos += d_vel;
}

} // end namespace hctg