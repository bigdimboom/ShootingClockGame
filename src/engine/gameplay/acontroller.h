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

	// ACCESSORS
	Pawn* pawn();
	ASprite* sprite();

	// MEMBER FUNCTIONS
	void addPawn(Pawn* pawn);
	void removePawn();

	void addSprite(ASprite* pawn);
	void removeSprite();

	virtual void preTick() override = 0;
	virtual void tick() override = 0;
};

// ACCESSORS
inline
Pawn* AController::pawn()
{
#ifdef _DEBUG
	std::cerr << "pawn is NULL.\n";
#endif
	return d_pawn;
}

inline
ASprite* AController::sprite()
{
#ifdef _DEBUG
	std::cerr << "sprite is NULL.\n";
#endif
	return d_sprite;
}

} // end namespace hctg