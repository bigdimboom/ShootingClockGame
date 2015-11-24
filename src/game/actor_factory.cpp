// actor_factory.cpp
#include "actor_factory.h"

#include "../engine/scene/scene.h"
#include <assert.h>
#include <list>

namespace mygame
{

static std::list< std::pair<ActorType, hcts::Actor*> > d_actorList;

ActorFactory::ActorFactory()
{
}


ActorFactory::~ActorFactory()
{
}

hcts::Actor* ActorFactory::createActor(hctm::Point2f pos)
{
	hcts::Actor* actor = new hcts::Actor(pos);
	d_actorList.push_back(std::make_pair(ActorType::BASIC_ACTOR, actor));
	return actor;
}

hctg::Pawn* ActorFactory::createPawn(hctm::Point2f pos)
{
	hctg::Pawn* actor = new hctg::Pawn(pos);
	d_actorList.push_back(std::make_pair(ActorType::BASIC_PAWN, actor));
	hcts::Scene::inst().addTickable(actor);
	return actor;
}

hctg::CollidableActor* ActorFactory::createCDActor(hctm::Point2f pos, float width, float height)
{
	hctg::CollidableActor* actor = new hctg::CollidableActor(pos, width, height);
	d_actorList.push_back(std::make_pair(ActorType::COLLIDABLE_ACTOR, actor));
	hcts::Scene::inst().addCollider(actor);
	return actor;
}

hctg::CollidablePawn* ActorFactory::createCDPawn(hctm::Point2f pos, float width, float height)
{
	hctg::CollidablePawn* actor = new hctg::CollidablePawn(pos, width, height);
	d_actorList.push_back(std::make_pair(ActorType::COLLIDABLE_PAWN, actor));
	hcts::Scene::inst().addCollider(actor);
	hcts::Scene::inst().addTickable(actor);
	return actor;
}

void ActorFactory::destoryActor(hcts::Actor* ptr)
{
	assert(ptr);
	for (auto i = d_actorList.begin(); i != d_actorList.end();++i)
	{
		if ((*i).second == ptr)
		{
			switch (((*i).first)) // test types
			{
				case ActorType::BASIC_ACTOR:
					break;
				case ActorType::BASIC_PAWN:
					hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(ptr));
					break;
				case ActorType::COLLIDABLE_ACTOR:
					hcts::Scene::inst().removeCollider(dynamic_cast<hctc::ICollider*>(ptr));
					break;
				case ActorType::COLLIDABLE_PAWN:
					hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(ptr));
					hcts::Scene::inst().removeCollider(dynamic_cast<hctc::ICollider*>(ptr));
					break;
			}
			delete ptr;
			d_actorList.erase(i);
			return;
		}
	}
}

} // end namespace mygame