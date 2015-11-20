// controller.h
#pragma once
#include "../scene/itickable.h"
#include "pawn.h"
#include "asprite.h"
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
	ASprite* d_sprite;
public:
	// CONSTRUCTOR
	AController();
	AController(Pawn* pawn, ASprite* sprite);

	// DESTRUCTOR
	virtual ~AController();

	void addPawn(Pawn* pawn);
	void removePawn();

	void addSprite(ASprite* pawn);
	void removeSprite();

	virtual void preTick() override = 0;
	virtual void tick() override = 0;
};

} // end namespace hctg