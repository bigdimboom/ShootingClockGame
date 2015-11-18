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

Character::~Character()
{
}

Character::Character(const Character & other)
{
}

Character::Character(Character && other)
{
}

// ASSIGNMENT OVERLOADS
Character& Character::operator = (const Character & other)
{
}

Character& Character::operator = (Character && other)
{
}

Character::~Character()
{
}

//ACCESSORS
const std::vector<ASprite*>& Character::sprites() const
{
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
	for (auto i = d_sprites.begin(); i != d_sprites.end(); ++i)
	{
		if (*i == sprite)
		{
			d_sprites.erase(i);
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