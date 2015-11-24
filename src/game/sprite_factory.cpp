// sprite_factory.cpp

#include "sprite_factory.h"

#include "../engine/scene/itickable.h"
#include "../engine/scene/scene.h"

#include <assert.h>
#include <list>

namespace mygame
{

static std::list< std::pair<SpriteType, hctg::ASprite*> > d_spriteList;


SpriteFactory::SpriteFactory()
{
}


SpriteFactory::~SpriteFactory()
{
}

mygame::BulletSprite* SpriteFactory::createBulletSprite(hctm::Point2f start, hctm::Point2f end)
{
	BulletSprite* sprite = new mygame::BulletSprite(start, end);
	hcts::Scene::inst().addDrawable(sprite);
	d_spriteList.push_back(std::make_pair(SpriteType::BULLET_SPRITE, sprite));
	return sprite;
}

mygame::ClockSprite* SpriteFactory::createClockSprite(hctm::Point2f center, float width)
{
	ClockSprite* sprite = new mygame::ClockSprite(center, width, width);
	hcts::Scene::inst().addDrawable(sprite);
	hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(sprite));
	d_spriteList.push_back(std::make_pair(SpriteType::CLOCK_SPRITE, sprite));
	return sprite;
}

mygame::CannonSprite* SpriteFactory::createCannonSprite(hctm::Point2f position)
{
	CannonSprite* sprite = new mygame::CannonSprite(position);
	hcts::Scene::inst().addDrawable(sprite);
	d_spriteList.push_back(std::make_pair(SpriteType::CANNON_SPRITE, sprite));
	return sprite;
}

void SpriteFactory::destorySprite(hctg::ASprite* ptr)
{
	assert(ptr);
	for (auto i = d_spriteList.begin(); i != d_spriteList.end();)
	{
		if ((*i).second == ptr)
		{
			switch ((*i).first) // test types
			{
				case SpriteType::CANNON_SPRITE:
					hcts::Scene::inst().removeDrawable(ptr);
					break;
				case SpriteType::BULLET_SPRITE:
					hcts::Scene::inst().removeDrawable(ptr);
					break;
				case SpriteType::CLOCK_SPRITE:
					hcts::Scene::inst().removeDrawable(ptr);
					hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(ptr));
					break;
			}
			delete ptr;
			i = d_spriteList.erase(i);
			return;
		}
	}
}

} // end namespace mygame