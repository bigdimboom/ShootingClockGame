// actor_factory.cpp
#include "actor_factory.h"

#include "../engine/scene/scene.h"
#include <assert.h>
#include <list>

namespace mygame
{

static std::list< hcts::Actor* > d_actorList;

ActorFactory::ActorFactory()
{
}


ActorFactory::~ActorFactory()
{
}

hcts::Actor* ActorFactory::createActor(hctm::Point2f pos)
{
	hcts::Actor* actor = new hcts::Actor(pos);
	d_actorList.push_back(actor);
	return actor;
}

hctg::Pawn* ActorFactory::createPawn(hctm::Point2f pos)
{
	hctg::Pawn* actor = new hctg::Pawn(pos);
	d_actorList.push_back(actor);
	return actor;
}

hctg::CollidableActor* ActorFactory::createCDActor(hctm::Point2f pos, float width, float height)
{
	hctg::CollidableActor* actor = new hctg::CollidableActor(pos, width, height);
	d_actorList.push_back(actor);
	//hcts::Scene::inst().addCollider(actor);
	return actor;
}

hctg::CollidablePawn* ActorFactory::createCDPawn(hctm::Point2f pos, float width, float height)
{
	hctg::CollidablePawn* actor = new hctg::CollidablePawn(pos, width, height);
	d_actorList.push_back(actor);
	//hcts::Scene::inst().addCollider(actor);
	//hcts::Scene::inst().addTickable(actor);
	return actor;
}

void ActorFactory::destoryActor(hcts::Actor* ptr)
{
	assert(ptr);
	for (auto i = d_actorList.begin(); i != d_actorList.end();++i)
	{
		if (*i == ptr)
		{
			d_actorList.erase(i);
			delete ptr;
			return;
		}
	}
}

hctg::Pawn* ActorFactory::clonePawn(ActorType type, hctg::Pawn* ptr)
{
	assert(ptr);
	switch (type)
	{
		case ActorType::BASIC_PAWN:
			break;
		case ActorType::COLLIDABLE_PAWN:
			break;
	}
	return nullptr;
}

} // end namespace mygame