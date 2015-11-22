// acontroller.cpp
#include "acontroller.h"
#include <assert.h>

namespace hctg
{

// CONSTRUCTORS
AController::AController()
	: d_pawn(nullptr)
	, d_sprite(nullptr)
	, d_collider(nullptr)
{
}

AController::AController(Pawn* pawn, ASprite* sprite)
	: d_pawn(pawn)
	, d_sprite(sprite)
	, d_collider(nullptr)
{
}

// DESTRUCTOR
AController::~AController()
{
}

// MEMBER FUNCTIONS
void AController::addPawn(Pawn* pawn)
{
	assert(pawn);
	d_pawn = pawn;
}

void AController::removePawn()
{
	d_pawn = nullptr;
}

void AController::addSprite(ASprite* sprite)
{
	assert(sprite);
	d_sprite = sprite;
}

void AController::removeSprite()
{
	d_sprite = nullptr;
}

void AController::addCollider(hctc::ICollider* cd)
{
	assert(cd);
	d_collider = cd;
}

void AController::removeCollider()
{
	d_collider = nullptr;
}

} // end 
