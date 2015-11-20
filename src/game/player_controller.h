// player_controller.h
#pragma once
#include "../engine/gameplay/acontroller.h"
#include "../engine/gameplay/character.h"
#include "../engine/events/event_bus.h"
#include "../engine/scene/scene.h"
#include "cannon_sprite.h"

namespace mygame
{

class PlayerController : public hctg::AController
{
public:
	hcte::EventListenerCallbacks d_eventHandler;
	const std::string kTurnLeft = "TURN_LEFT";
	const std::string kTurnRight = "TURN_RIGHT";
	const std::string kOpenFire = "FIRE";

	float d_deltaAngle;
	float d_maxAngle;
	float d_minAngle;
	hctm::Point2f d_pos;



public:
	// CONSTRUCTOR
	PlayerController();

	// DESTRUCTOR
	~PlayerController();

	// MEMBERS
	void init(hctm::Point2f pos, float max, float min, float delta)
	{
		d_pos = pos;
		d_maxAngle = max;
		d_minAngle = min;
		d_deltaAngle = delta;

		d_sprite = new CannonSprite(d_pos);

		if (d_sprite)
		{
			hcts::Scene::inst().addDrawable(d_sprite);
		}

		if (d_pawn)
		{
			hcts::Scene::inst().addTickable(d_pawn);
		}

		d_eventHandler = [&](const hcte::IEvent & ev){

			static float angle = 90.0f;

			if (d_sprite)
			{
				if (ev.message() == kTurnRight && angle <= d_maxAngle)
				{
					d_sprite->rotate(d_pos, d_deltaAngle);
					angle += d_deltaAngle;
				}
				else if (ev.message() == kTurnLeft && angle >= d_minAngle)
				{
					d_sprite->rotate(d_pos, -d_deltaAngle);
					angle -= d_deltaAngle;
				}
				else if (ev.message() == kOpenFire)
				{

				}
			}
		};
	}


	void preTick() override;
	void tick() override;

};

} // end namespace mygame