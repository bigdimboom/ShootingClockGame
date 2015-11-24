// pawn_factory.h
#pragma once

#include "../engine/scene/actor.h"
#include "../engine/gameplay/pawn.h"
#include "../engine/gameplay/collidable_actor.h"
#include "../engine/gameplay/collidable_pawn.h"

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

	static hcts::Actor* createActor(hctm::Point2f pos);
	static hctg::Pawn* createPawn(hctm::Point2f pos);
	static hctg::CollidableActor* createCDActor(hctm::Point2f pos, float width, float height);
	static hctg::CollidablePawn* createCDPawn(hctm::Point2f pos, float width, float height);
	static void destoryActor(hcts::Actor* actor);
};

} // end namespace mygame