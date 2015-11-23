// player_controller.h
#pragma once
#include "../engine/gameplay/acontroller.h"
#include "../engine/events/event_bus.h"
#include "../engine/scene/scene.h"
#include "cannon_sprite.h"
#include "bullet_controller.h"
#include <vector>

namespace mygame
{

class PlayerController : public hctg::AController
{
private:
	hcte::EventListenerCallbacks d_eventHandlerInput;
	hcte::EventListenerCallbacks d_eventHandlerHit;

	const std::string kTurnLeft = "TURN_LEFT";
	const std::string kTurnRight = "TURN_RIGHT";
	const std::string kOpenFire = "FIRE";

	float d_deltaAngle;
	float d_maxAngle;
	float d_minAngle;

	hctm::Point2f d_position;
	hctm::Point2f d_head;
	std::vector<BulletController*> d_gun;

	// HELPERS
	void _fire();

public:
	// CONSTRUCTOR
	PlayerController();

	// DESTRUCTOR
	~PlayerController();

	// MEMBERS
	void init(hctm::Point2f pos, float max, float min, float delta);
	void preTick() override;
	void tick() override;
	void postTick() override;
	void cleanUp();

};

} // end namespace mygame