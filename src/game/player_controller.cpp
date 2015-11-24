// player_controller.cpp
#include "player_controller.h"


#include "bullet_sprite.h"
#include "../engine/gameplay/collidable_pawn.h"
#include "clock_sprite.h"

#include "../engine/data/resource.h"
#include "sprite_factory.h"

#include <assert.h>

namespace mygame
{

// HELPERS
void PlayerController::_fire()
{
	unsigned int cont = d_gun.size();

	d_gun.push_back(new BulletController());

	BulletController* bctrl = d_gun[d_gun.size() - 1];

	auto dir = d_head - d_position;
	dir.normalize();

	auto center = d_head + dir * 10.0f;

	hctg::CollidablePawn* bulletPawn = new hctg::CollidablePawn(center, 5.0f, 5.0f);
	bulletPawn->setVelocity(dir * 5.0f);
	bulletPawn->setFlags(DYNAMIC_COLLIDER | BULLET_COLLIDER);

	auto start = bulletPawn->bounds().downRightPoint();
	auto end = bulletPawn->bounds().topLeftPoint();
	BulletSprite* bulletSprite = mygame::SpriteFactory::createBulletSprite(start, end);

	bctrl->addPawn(bulletPawn);
	bctrl->addCollider(bulletPawn);
	bctrl->addSprite(bulletSprite);

	hcts::Scene::inst().addTickable(bctrl);
	hcts::Scene::inst().addTickable(bctrl->pawn());
	hcts::Scene::inst().addCollider(bctrl->collider());
	hcts::Scene::inst().addDrawable(bctrl->sprite());
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
		if ( ((*i)->collider()->flags() & BULLET_HIT ) == BULLET_HIT) // the bullet is hit something
		{
			BulletController* bctrl = (*i);
			hcts::Scene::inst().removeTickable(bctrl);
			hcts::Scene::inst().removeTickable(bctrl->pawn());
			hcts::Scene::inst().removeCollider(bctrl->collider());
			hcts::Scene::inst().removeDrawable(bctrl->sprite());

			delete bctrl->pawn();
			bctrl->removePawn();
			bctrl->removeCollider();
			delete bctrl->sprite();
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
	for (auto i = d_gun.begin(); i != d_gun.end(); ++i)
	{
		delete *i;
	}

	mygame::SpriteFactory::destorySprite(d_sprite);
	removeSprite();
}

} // end namespace mygame