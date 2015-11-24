// sprite_factory.cpp

#include "sprite_factory.h"

#include "../engine/scene/itickable.h"
#include "../engine/scene/scene.h"

#include <assert.h>
#include <list>

namespace mygame
{

static std::list< hctg::ASprite* > d_spriteList;


SpriteFactory::SpriteFactory()
{
}


SpriteFactory::~SpriteFactory()
{
}

mygame::BulletSprite* SpriteFactory::createBulletSprite(hctm::Point2f start, hctm::Point2f end)
{
	BulletSprite* sprite = new mygame::BulletSprite(start, end);
	//hcts::Scene::inst().addDrawable(sprite);
	d_spriteList.push_back( sprite);
	return sprite;
}

mygame::ClockSprite* SpriteFactory::createClockSprite(hctm::Point2f center, float width)
{
	ClockSprite* sprite = new mygame::ClockSprite(center, width, width);
	//hcts::Scene::inst().addDrawable(sprite);
	//hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(sprite));
	d_spriteList.push_back(sprite);
	return sprite;
}

mygame::CannonSprite* SpriteFactory::createCannonSprite(hctm::Point2f position)
{
	CannonSprite* sprite = new mygame::CannonSprite(position);
	//hcts::Scene::inst().addDrawable(sprite);
	d_spriteList.push_back(sprite);
	return sprite;
}

void SpriteFactory::destorySprite(hctg::ASprite* ptr)
{
	assert(ptr);
	for (auto i = d_spriteList.begin(); i != d_spriteList.end();++i)
	{
		if (*i == ptr)
		{
			d_spriteList.erase(i);
			delete ptr;
			return;
		}
	}
}

hctg::ASprite* SpriteFactory::cloneSprite(SpriteType type, hctg::ASprite* ptr)
{
	//switch (type)
	//{

	//}
	return nullptr;
}

} // end namespace mygame