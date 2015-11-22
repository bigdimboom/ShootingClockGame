// colock_controller.h
#pragma 
#include "../engine/gameplay/acontroller.h"
#include "clock_sprite.h"
#include "../engine/gameplay/collidable_pawn.h"
#include "../engine/scene/scene.h"

namespace mygame
{

class ClockController : public hctg::AController
{
public:
	ClockController();
	virtual ~ClockController();
	void preTick() override;
	void tick() override;
};

} // end namespace mygame