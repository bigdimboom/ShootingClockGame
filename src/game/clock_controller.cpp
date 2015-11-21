// colock_controller.cpp
#include "clock_controller.h"
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
	assert(d_collider && d_pawn && d_sprite);

	auto & set = hcts::Scene::inst().getSceneGraph().query(d_collider);
	for (auto & cd : set)
	{
		if (d_collider->doesCollide(cd->bounds()))
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

	d_pawn->tick();
	d_collider->bounds().translate(d_pawn->positionXY() - d_sprite->position());
	d_sprite->setPostion(d_pawn->positionXY());
}

} // end namespace mygame