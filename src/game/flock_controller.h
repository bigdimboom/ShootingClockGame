// flock_controller.h
#pragma once
#include "../engine/gameplay/acontroller.h"
#include "clock_controller.h"
#include "../engine/scene/scene.h"
#include "../engine/gameplay/collidable_pawn.h"
#include "clock_sprite.h"

namespace mygame
{

class FlockController : public hctg::AController
{
private:
	hctm::Point2f _randomPos(hctm::Point2f start,
						  float width, float height);

	hctm::Point2f _randomVel(float speed);

	void _createClock(hctm::Point2f pos, hctm::Point2f vel, float width = 100.0f);
	void _destoryClock(ClockController* ptr);


	std::vector<ClockController*> d_clocks;

public:
	FlockController();
	~FlockController();

	// MEMBERS
	void init();
	void preTick() override;
	void tick() override;
	void postTick() override;
	void cleanUp();

	void addToPipeline() override;
	void removeFromPipeline() override;
};

} // end namespace mygame