// player_controller.cpp
#include "player_controller.h"

namespace mygame
{


PlayerController::PlayerController()
	: AController()
	, d_deltaAngle(0)
	, d_maxAngle(0)
	, d_minAngle(0)
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().registerListener(ev, &d_eventHandler);
}

PlayerController::~PlayerController()
{
	hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD);
	hcte::EventBus::inst().deRegisterListener(ev, &d_eventHandler);
	if (d_sprite)
	{
		delete d_sprite;
	}
	if (d_pawn)
	{
		delete d_pawn;
	}
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