// character.cpp
#include "character.h"
#include <assert.h>
#include <algorithm>

namespace hctg
{

Character::Character(hctm::Point2f pos, hctm::Point2f vel)
	: Pawn(pos, vel)
{
}

Character::Character(const Character & other)
	: d_sprite(other.d_sprite)
	, Pawn(other.d_pos, other.d_vel)
{
}

Character::Character(Character && other)
	: d_sprite(std::move(other.d_sprite))
	, Pawn( std::move(other.d_pos), std::move(other.d_vel) )
{
}

// ASSIGNMENT OVERLOADS
Character& Character::operator = (const Character & other)
{
	if (this != &other)
	{
		d_pos = other.d_pos;
		d_vel = other.d_vel;
		d_sprite = other.d_sprite;
	}
	return *this;
}

Character& Character::operator = (Character && other)
{
	if (this != &other)
	{
		d_pos = std::move(other.d_pos);
		d_vel = std::move(other.d_vel);
		d_sprite = std::move(other.d_sprite);
	}
	return *this;
}

Character::~Character()
{
	removeSprite();
}

// MEMBER FUNCTIONS
void Character::attachSprite(ASprite* sprite)
{
	assert(sprite);
	d_sprite = sprite;
}

void Character::removeSprite()
{
	d_sprite = nullptr;
}

void Character::preTick()
{
	Pawn::preTick();
}

void Character::tick()
{
	Pawn::tick();
}

}// end namespace hctg