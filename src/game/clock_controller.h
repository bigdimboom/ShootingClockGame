// colock_controller.h
#pragma once
#include "clock_sprite.h"
#include "../engine/gameplay/collidable_character.h"

namespace mygame
{

class ClockController
{
public:
	hctg::CollidableCharacter* d_character;
	mygame::ClockSprite* d_sprite;

public:
	ClockController();
	~ClockController();


};

} // end namespace mygame