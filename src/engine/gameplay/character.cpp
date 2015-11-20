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
	: d_sprites(other.d_sprites)
	, Pawn(other.d_pos, other.d_vel)
{
}

Character::Character(Character && other)
	: d_sprites(std::move(other.d_sprites))
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
		d_sprites = other.d_sprites;
	}
	return *this;
}

Character& Character::operator = (Character && other)
{
	if (this != &other)
	{
		d_pos = std::move(other.d_pos);
		d_vel = std::move(other.d_vel);
		d_sprites = std::move(other.d_sprites);
	}
	return *this;
}

Character::~Character()
{
	for (auto &i : d_sprites)
	{
		i = nullptr;
	}
}

//ACCESSORS
const std::vector<ASprite*>& Character::sprites() const
{
	return d_sprites;
}

// MEMBER FUNCTIONS
void Character::attachSprites(ASprite* sprite)
{
	assert(sprite);
	d_sprites.push_back(sprite);
}

void Character::removeSprites(ASprite* sprite)
{
	assert(sprite);
	auto itr = d_sprites.begin();
	while (itr != d_sprites.end())
	{
		if (*itr == sprite)
		{
			d_sprites.erase(itr);
		}
		else
		{
			++itr;
		}
	}
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