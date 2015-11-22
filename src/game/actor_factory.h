// pawn_factory.h
#pragma once

#include "../engine/scene/actor.h"
#include "../engine/gameplay/pawn.h"

namespace mygame
{

enum class ActorType
{
	BASIC_ACTOR,
	COLLIDABLE_ACTOR,
	BASIC_PAWN,
	COLLIDABLE_PAWN
};

class ActorFactory
{
public:
	ActorFactory();
	~ActorFactory();
	static hcts::Actor* createActor(ActorType type);
};

} // end namespace mygame