// player_controller.cpp
#include "player_controller.h"
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
	d_eventHandler = [&](const hcte::IEvent & ev)
	{
		static float angle = 90.0f;

		if (d_sprite)
		{
			if (ev.message() == kTurnRight && angle <= d_maxAngle)
			{
				d_sprite->rotate(d_sprite->position(), d_deltaAngle);
				angle += d_deltaAngle;
			}
			else if (ev.message() == kTurnLeft && angle >= d_minAngle)
			{
				d_sprite->rotate(d_sprite->position(), -d_deltaAngle);
				angle -= d_deltaAngle;
			}
			else if (ev.message() == kOpenFire)
			{

			}
		}
	};

	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().registerListener(ev, &d_eventHandler);
}

PlayerController::~PlayerController()
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().deRegisterListener(ev, &d_eventHandler);
}

void PlayerController::preTick()
{
	// DO NOTHING
}

void PlayerController::tick()
{
	// DO NOTHING
}

} // end namespace mygame