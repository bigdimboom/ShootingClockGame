// colock_controller.h
#pragma 
#include "../engine/gameplay/acontroller.h"

namespace mygame
{

class ClockController : public hctg::AController
{
public:
	ClockController();
	virtual ~ClockController();
	void preTick() override;
	void tick() override;
	void postTick() override;

	void addToPipeline() override;
	void removeFromPipeline() override;
};

} // end namespace mygame