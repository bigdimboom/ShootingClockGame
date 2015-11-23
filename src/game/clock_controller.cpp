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

				break;

				//hcts::Scene::inst().removeTickable(d_pawn);
				//hcts::Scene::inst().removeDrawable(d_sprite);
				//hcts::Scene::inst().removeTickable(dynamic_cast<ITickable*>(d_sprite));
				//hcts::Scene::inst().removeCollider(d_collider);

				//delete d_sprite;
				//delete d_pawn;

				//removeCollider();
				//removePawn();
				//removeSprite();

				//return;
			}
		}

		d_pawn->tick();
		d_collider->bounds().translate(d_pawn->positionXY() - d_sprite->position());
		d_sprite->setPostion(d_pawn->positionXY());
	}

}

void ClockController::postTick()
{

}

} // end namespace mygame