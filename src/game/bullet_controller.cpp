// cullet_controller.cpp
#include "bullet_controller.h"
#include "../engine/scene/scene.h"
#include "../engine/events/event_bus.h"
#include <assert.h>

namespace mygame
{

BulletController::BulletController()
	: AController()
{
}


BulletController::~BulletController()
{
}

void BulletController::preTick()
{
}

void BulletController::tick()
{
	assert(d_collider && d_pawn && d_sprite);

	auto & set = hcts::Scene::inst().getSceneGraph().query(d_collider);
	for (auto & cd : set)
	{
		if (d_collider->doesCollide(cd->bounds()))
		{
			d_pawn->setVelocity(-d_pawn->velocity());
			d_pawn->tick(); // one tick back
			
			//if ((cd->flags() & BULLET_COLLIDER) == BULLET_COLLIDER) // if target is a bullet, do nothing
			//{
			//	continue;
			//}

			d_collider->setFlags(d_collider->flags() | BULLET_HIT);
		}
	}

	d_pawn->tick();
	d_collider->bounds().translate(d_pawn->positionXY() - d_sprite->position());
	d_sprite->setPostion(d_pawn->positionXY());
}

void BulletController::postTick()
{
}

} //end namespace mygame