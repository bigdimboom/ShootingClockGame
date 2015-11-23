// actor_factory.cpp
#include "actor_factory.h"


namespace mygame
{

ActorFactory::ActorFactory()
{
}


ActorFactory::~ActorFactory()
{
}

hcts::Actor* ActorFactory::createActor(ActorType type)
{
	switch (type)
	{
		case ActorType::BASIC_ACTOR:
			break;
		case ActorType::BASIC_PAWN:
			break;
		case ActorType::COLLIDABLE_ACTOR:
			break;
		case ActorType::COLLIDABLE_PAWN:
			break;
		default:
			break;
	}

	return nullptr;
}

} // end namespace mygame