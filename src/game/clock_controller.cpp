// colock_controller.cpp
#include "clock_controller.h"
#include "../engine/scene/scene.h"
#include "../engine/data/resource.h"
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

				d_pawn->setVelocity(-d_pawn->velocity());
				d_pawn->tick(); // one tick back

				if ((cd->flags() & N_WALL_COLLIDER) == N_WALL_COLLIDER) // if target is a north wall.
				{
					auto posN = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH) * 0.5f, 
											  0.0f);
					auto posE = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH), 
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT) * 0.5f);

					auto dir = posE - posN; // from north to east

					dir.normalize();
					auto currentVel = d_pawn->velocity();
					auto speed = currentVel.length();
					dir *= speed;
					d_pawn->setVelocity(dir);
				}
				else if ((cd->flags() & S_WALL_COLLIDER) == S_WALL_COLLIDER)
				{
					auto posS = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH) * 0.5f,
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT));

					auto posW = hctm::Point2f(0.0f,
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT) * 0.5f);

					auto dir = posW - posS; // from s to w

					dir.normalize();
					auto currentVel = d_pawn->velocity();
					auto speed = currentVel.length();
					dir *= speed;
					d_pawn->setVelocity(dir);

				}
				else if ((cd->flags() & W_WALL_COLLIDER) == W_WALL_COLLIDER) 
				{
					auto posW = hctm::Point2f(0.0f,
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT) * 0.5f);
					auto posN = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH) * 0.5f,
											  0.0f);

					auto dir = posN - posW;

					dir.normalize();
					auto currentVel = d_pawn->velocity();
					auto speed = currentVel.length();
					dir *= speed;
					d_pawn->setVelocity(dir);

				}
				else if ((cd->flags() & E_WALL_COLLIDER) == E_WALL_COLLIDER)
				{
					auto posS = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH) * 0.5f,
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT));
					auto posE = hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH),
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT) * 0.5f);

					auto dir = posS - posE;

					dir.normalize();
					auto currentVel = d_pawn->velocity();
					auto speed = currentVel.length();
					dir *= speed;
					d_pawn->setVelocity(dir);
				}
				else
				{
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