// sprite_factory.cpp
#include "sprite_factory.h"
#include "cannon_sprite.h"
#include "clock_sprite.h"
#include "bullet_sprite.h"

#include "../engine/scene/itickable.h"
#include "../engine/scene/scene.h"

#include <list>
#include <iostream>

namespace mygame
{

static std::list< std::pair<SpriteType, hctg::ASprite*> > d_spriteList;


SpriteFactory::SpriteFactory()
{
}


SpriteFactory::~SpriteFactory()
{
}

hctg::ASprite* SpriteFactory::createSprite(SpriteType type)
{
	// read data from resource manager
	hctm::Point2f position; // pos is on the middle of bottom line
	float width; // width of a clock
	hctm::Point2f start; // start of the bullet
	hctm::Point2f end;  // end of the bullet

	hctg::ASprite* sprite = nullptr;

	switch (type)
	{
		case SpriteType::CANNON_SPRITE:
			sprite = new mygame::CannonSprite(position); 
			hcts::Scene::inst().addDrawable(sprite);
			break;
		case SpriteType::BULLET_SPRITE:
			sprite = new mygame::BulletSprite(start, end);
			hcts::Scene::inst().addDrawable(sprite);
			break;
		case SpriteType::CLOCK_SPRITE:
			sprite = new mygame::ClockSprite(position, width, width);
			hcts::Scene::inst().addDrawable(sprite);
			hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(sprite));
			break;
		default:
#ifdef _DEBUG
			std::cerr << "No valid sprite allocated.\n";
#endif
			break;
	}

	if (sprite)
	{
		d_spriteList.push_back(std::make_pair(type, sprite));
		return sprite;
	}

	return nullptr;
}

void SpriteFactory::destorySprite(hctg::ASprite* ptr)
{
	for (auto i = d_spriteList.begin(); i != d_spriteList.end();)
	{
		if ( (*i).second == ptr)
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
			i = d_spriteList.erase(i);
			delete ptr;
		}
		else
		{
			++i;
		}
	}
}

} // end namespace mygame