// controller.h
#pragma once
#include "../scene/itickable.h"
#include "../collision/icollider.h"
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
	hctc::ICollider* d_collider;
public:
	// CONSTRUCTOR
	AController();
	AController(Pawn* pawn, ASprite* sprite);

	// DESTRUCTOR
	virtual ~AController();

	// ACCESSORS
	Pawn* pawn();
	ASprite* sprite();
	hctc::ICollider* collider();

	// MEMBER FUNCTIONS
	void addPawn(Pawn* pawn);
	void removePawn();

	void addSprite(ASprite* pawn);
	void removeSprite();

	void addCollider(hctc::ICollider* pawn);
	void removeCollider();

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

inline
hctc::ICollider* AController::collider()
{
#ifdef _DEBUG
	std::cerr << "collider is NULL.\n";
#endif
	return d_collider;
}

} // end namespace hctg