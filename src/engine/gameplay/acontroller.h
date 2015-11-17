// controller.h
#pragma once
#include "../scene/itickable.h"
#include "apawn.h"
#include <vector>
// controller is reponsible of GC.

namespace hctg
{
class AController : public hcts::ITickable
{
private:
	AController(const AController & other) = delete;
	AController(AController && other) = delete;
	AController& operator=(const AController &) = delete;
	AController& operator=(AController &&) = delete;
protected:

	// the amount of pawns
	// the operations' complexity of a container
	//...
	// defines what kind of container I choose.

public:
	// CONSTRUCTOR
	AController();

	// DESTRUCTOR
	~AController();

	virtual void addPawn(APawn* pawn) = 0;
	virtual void removePawn(APawn* pawn) = 0;

	virtual void preTick() = 0;
	virtual void tick() = 0;
};

} // end namespace hctg