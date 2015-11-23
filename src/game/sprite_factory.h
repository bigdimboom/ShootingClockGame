// sprite_factory.h
#pragma once
#include "../engine/gameplay/asprite.h"

namespace mygame
{

enum class SpriteType
{
	CANNON_SPRITE,
	BULLET_SPRITE,
	CLOCK_SPRITE
};

class SpriteFactory
{

public:
	SpriteFactory();
	~SpriteFactory();

	static hctg::ASprite* createSprite(SpriteType type);
	static void destorySprite(hctg::ASprite* ptr);

};

} // end namespace mygame