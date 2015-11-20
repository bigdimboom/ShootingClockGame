// player_controller.h
#pragma once
#include "../engine/gameplay/acontroller.h"
#include "../engine/gameplay/character.h"
#include "cannon_sprite.h"
#include "../engine/events/event_bus.h"

namespace mygame
{

class PlayerController : public hctg::AController
{
public:
	// MEMBERS
	hctg::Character d_cannon;
	CannonSprite d_sprite;

	hcte::EventListenerCallbacks eventHandler;

	// CONSTRUCTOR
	PlayerController(hctm::Point2f pos);

	// DESTRUCTOR
	~PlayerController();

	void init();
	void preTick() override;
	void tick() override;

	const std::string kTurnLeft = "TURN_LEFT";
	const std::string kTurnRight = "TURN_RIGHT";
	const std::string kOpenFire = "FIRE";
};

} // end namespace mygame