// colock_controller.cpp
#include "clock_controller.h"
#include "../engine/scene/scene.h"
#include <assert.h>

namespace mygame
{

ClockController::ClockController()
{
}

ClockController::~ClockController()
{
}

void ClockController::preTick()
{
}

void ClockController::tick()
{
	//assert(d_collider && d_pawn && d_sprite);

	if (d_collider && d_pawn && d_sprite)
	{
		auto & set = hcts::Scene::inst().getSceneGraph().query(d_collider);
		for (auto & cd : set)
		{
			if (d_collider->doesCollide(cd->bounds()))
			{
				if ((cd->flags() & BULLET_COLLIDER) == BULLET_COLLIDER) // if target is a bullet, do nothing
				{
					d_collider->setFlags(d_collider->flags() | HIT_BY_BULLET);
					continue;
				}
				if ((cd->flags() & WALL_COLLIDER) == WALL_COLLIDER) // if target is a wall, negate velocity
				{
					d_pawn->setVelocity(-d_pawn->velocity());
					d_pawn->tick(); // one tick back
				}
				else
				{
					d_pawn->setVelocity(-d_pawn->velocity());
					d_pawn->tick(); // one tick back

					auto dir = d_collider->bounds().getCenter()
						- cd->bounds().getCenter();
					// reverse dirction

					float speed = d_pawn->velocity().length();
					dir.normalize();
					dir *= speed;

					d_pawn->setVelocity(dir);
				}
			}
		}
	}
	d_pawn->tick();
	d_collider->bounds().translate(d_pawn->positionXY() - d_sprite->position());
	d_sprite->setPostion(d_pawn->positionXY());

}

void ClockController::postTick()
{

}

void ClockController::addToPipeline()
{
	if (d_sprite)
	{
		hcts::Scene::inst().addDrawable(d_sprite);
		hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(d_sprite));
	}
	if (d_pawn)
	{
		hcts::Scene::inst().addCollider(dynamic_cast<hctc::ICollider*>(d_pawn));
	}

	hcts::Scene::inst().addTickable(this);
}

void ClockController::removeFromPipeline()
{
	if (d_sprite)
	{
		hcts::Scene::inst().removeDrawable(d_sprite);
		hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(d_sprite));
	}
	if (d_pawn)
	{
		hcts::Scene::inst().removeCollider(dynamic_cast<hctc::ICollider*>(d_pawn));
	}

	hcts::Scene::inst().removeTickable(this);
}

} // end namespace mygame