// player_controller.cpp
#include "player_controller.h"


#include "bullet_sprite.h"
#include "../engine/gameplay/collidable_pawn.h"
#include "clock_sprite.h"

#include <assert.h>

namespace mygame
{


PlayerController::PlayerController(hctm::Point2f postion, float max, float min, float delta)
	: AController()
	, d_deltaAngle(delta)
	, d_maxAngle(max)
	, d_minAngle(min)
	, d_position(postion)
	, d_head(hctm::Point2f(postion.x(), postion.y() - 30.0f))
{

	d_eventHandlerInput = [&](const hcte::IEvent & ev)
	{
		static float angle = 90.0f;

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
					unsigned int cont = d_gun.size();

					d_gun.push_back(new BulletController());

					BulletController* bctrl = d_gun[d_gun.size() - 1];

					auto dir = d_head - d_position;
					dir.normalize();
					auto start = d_head + dir * 10.0f;
					start.setY(start.y() - 2.0f);
					auto center = start;
					start.setX(start.x() - 1.0f);
					start.setY(start.y() - 2.0f);
					auto end = hctm::Point2f(start.x() + 2.0f, start.y() + 4.0f);

					BulletSprite* bulletSprite = new BulletSprite(start, end);
					//mygame::ClockSprite* bulletSprite = new ClockSprite(center, 10.0, 10.0);
					hctg::CollidablePawn* bulletPawn = new hctg::CollidablePawn(center, 5.0f, 5.0f);
					bulletPawn->setVelocity(dir * 3.0f);
					bulletPawn->setFlags(DYNAMIC_COLLIDER);

					bctrl->addPawn(bulletPawn);
					bctrl->addCollider(bulletPawn);
					bctrl->addSprite(bulletSprite);

					hcts::Scene::inst().addTickable(bctrl);
					hcts::Scene::inst().addTickable(bctrl->pawn());
					hcts::Scene::inst().addCollider(bctrl->collider());
					hcts::Scene::inst().addDrawable(bctrl->sprite());
				}
			}
		}
	};

	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().registerListener(ev, &d_eventHandlerInput);
}

PlayerController::~PlayerController()
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().deRegisterListener(ev, &d_eventHandlerInput);
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
		if ((*i)->collider()->flags() == (RESERVE_COLLIDER2 | DYNAMIC_COLLIDER))
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

} // end namespace mygame