// player_controller.cpp
#include "player_controller.h"

#include "sprite_factory.h"
#include "actor_factory.h"
#include "../engine/data/resource.h"

#include <assert.h>

namespace mygame
{

// HELPERS
void PlayerController::_fire()
{
	//unsigned int cont = d_gun.size();

	BulletController* bctrl = new BulletController();

	auto dir = d_head - d_position;
	dir.normalize();

	auto center = d_head + dir * 10.0f;

	hctg::CollidablePawn* bulletPawn = mygame::ActorFactory::createCDPawn
		(
		center,
		hctd::Resource::inst().getValue(hctd::BULLET_WIDTH),
		hctd::Resource::inst().getValue(hctd::BULLET_LENGTH)
		);

	bulletPawn->setVelocity(dir * hctd::Resource::inst().getValue(hctd::BULLET_SPEED));
	bulletPawn->setFlags(DYNAMIC_COLLIDER | BULLET_COLLIDER);

	auto start = bulletPawn->bounds().downRightPoint();
	auto end = bulletPawn->bounds().topLeftPoint();
	BulletSprite* bulletSprite = mygame::SpriteFactory::createBulletSprite(start, end);

	bctrl->addPawn(bulletPawn);
	bctrl->addCollider(bulletPawn);
	bctrl->addSprite(bulletSprite);

	bctrl->addToPipeline();

	d_gun.push_back(bctrl);
}

PlayerController::PlayerController()
	: AController()
	, d_deltaAngle(0)
	, d_maxAngle(0)
	, d_minAngle(0)
	, d_position(0)
	, d_head(0)
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().registerListener(ev, &d_eventHandlerInput);
}

PlayerController::~PlayerController()
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().deRegisterListener(ev, &d_eventHandlerInput);
}

void PlayerController::init()
{
	d_position = hctm::Point2f(hctd::Resource::inst().getValue(hctd::CANNON_START_POS_X),
							   hctd::Resource::inst().getValue(hctd::CANNON_START_POS_Y));

	d_head = hctm::Point2f(hctd::Resource::inst().getValue(hctd::CANNON_HEAD_START_POS_X),
						   hctd::Resource::inst().getValue(hctd::CANNON_HEAD_START_POS_Y));

	d_maxAngle = hctd::Resource::inst().getValue(hctd::CANNON_MAX_ANGLE);
	d_minAngle = hctd::Resource::inst().getValue(hctd::CANNON_MIN_ANGLE);
	d_deltaAngle = hctd::Resource::inst().getValue(hctd::CANNON_DELTA_ROTATION);

	d_eventHandlerInput = [&](const hcte::IEvent & ev)
	{
		static float angle = 90.0f; // pointing at 12 o'clock

		if (ev.type() == hcte::EventType::PLAYER_CMD)
		{

			if (d_sprite)
			{
				if (ev.message() == kTurnRight && angle <= d_maxAngle)
				{
					d_sprite->rotate(d_sprite->position(), d_deltaAngle);
					d_head.rotate(d_sprite->position(), d_deltaAngle);
					angle += d_deltaAngle;
				}
				else if (ev.message() == kTurnLeft && angle >= d_minAngle)
				{
					d_sprite->rotate(d_sprite->position(), -d_deltaAngle);
					d_head.rotate(d_sprite->position(), -d_deltaAngle);
					angle -= d_deltaAngle;
				}
				else if (ev.message() == kOpenFire)
				{
					_fire();
				}
			}
		}
	};

	addSprite(mygame::SpriteFactory::createCannonSprite(d_position));
	addToPipeline();
}

void PlayerController::preTick()
{
	// DO NOTHING
}

void PlayerController::tick()
{
	// DO NOTHING
	// You can not delete tick in the tick
}

void PlayerController::postTick()
{
	for (auto i = d_gun.begin(); i != d_gun.end();)
	{
		if (((*i)->collider()->flags() & BULLET_HIT) == BULLET_HIT) // the bullet is hit something
		{
			BulletController* bctrl = (*i);
			
			bctrl->removeFromPipeline();

			mygame::ActorFactory::destoryActor(bctrl->pawn());
			mygame::SpriteFactory::destorySprite(bctrl->sprite());
			bctrl->removePawn();
			bctrl->removeCollider();
			bctrl->removeSprite();

			delete bctrl;
			i = d_gun.erase(i);
		}
		else
		{
			++i;
		}
	}
}

void PlayerController::cleanUp()
{
	for (auto i = d_gun.begin(); i != d_gun.end();++i)
	{
		BulletController* bctrl = (*i);

		bctrl->removeFromPipeline();

		mygame::ActorFactory::destoryActor(bctrl->pawn());
		mygame::SpriteFactory::destorySprite(bctrl->sprite());
		bctrl->removePawn();
		bctrl->removeCollider();
		bctrl->removeSprite();

		delete bctrl;

		*i = nullptr;
	}
	d_gun.clear();


	removeFromPipeline(); 
	mygame::SpriteFactory::destorySprite(d_sprite);
	removeSprite();
}

void PlayerController::addToPipeline()
{
	if (d_sprite)
	{
		hcts::Scene::inst().addDrawable(d_sprite);
	}

	hcts::Scene::inst().addTickable(this);
}

void PlayerController::removeFromPipeline()
{
	if (d_sprite)
	{
		hcts::Scene::inst().removeDrawable(d_sprite);
	}
	hcts::Scene::inst().removeTickable(this);
}

} // end namespace mygame