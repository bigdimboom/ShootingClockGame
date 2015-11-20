// player_controller.cpp
#include "player_controller.h"

namespace mygame
{


PlayerController::PlayerController(hctm::Point2f pos)
	: hctg::AController()
	, d_cannon(pos)
	, d_sprite(pos)
{
	eventHandler = [&](const hcte::IEvent & ev){

		static float angle = 90.0f;
		const float delta = 1.0f;

		if (ev.message() == kTurnLeft && angle >= 0.0f)
		{
			d_sprite.rotate(d_cannon.positionXY(), -delta);
			angle -= delta;
		}
		else if (ev.message() == kTurnRight && angle <= 180.0f)
		{
			d_sprite.rotate(d_cannon.positionXY(), delta);
			angle += delta;
		}
	};
}

PlayerController::~PlayerController()
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().deRegisterListener(ev, &eventHandler);
}

void PlayerController::init()
{
	hctg::AController::addPawn(&d_cannon);
	d_cannon.attachSprites(&d_sprite);

	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().registerListener(ev, &eventHandler);

}

void PlayerController::preTick()
{
}

void PlayerController::tick()
{
}

} // end namespace mygame