// controller.h
#pragma once
#include "../scene/itickable.h"
#include "pawn.h"
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
	Pawn* d_pawn;
public:
	// CONSTRUCTOR
	AController(Pawn* pawn = nullptr);

	// DESTRUCTOR
	virtual ~AController();

	void addPawn(Pawn* pawn);
	void removePawn();

	virtual void preTick() override = 0;
	virtual void tick() override = 0;
};

} // end namespace hctg