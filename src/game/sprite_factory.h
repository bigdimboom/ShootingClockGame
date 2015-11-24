// sprite_factory.h
#pragma once
#include "../engine/gameplay/asprite.h"
#include "../game/bullet_sprite.h"
#include "../game/clock_sprite.h"
#include "../game/cannon_sprite.h"

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

	static mygame::BulletSprite* createBulletSprite(hctm::Point2f start, hctm::Point2f end);
	static mygame::ClockSprite* createClockSprite(hctm::Point2f center, float width);
	static mygame::CannonSprite* createCannonSprite(hctm::Point2f position);
	
	static void destorySprite(hctg::ASprite* ptr);

	static hctg::ASprite* cloneSprite(SpriteType type, hctg::ASprite* ptr);

};

} // end namespace mygame