// acontroller.cpp
#include "acontroller.h"
#include <assert.h>

namespace hctg
{

// CONSTRUCTORS
AController::AController()
	: d_pawn(nullptr)
	, d_sprite(nullptr)
{
}

AController::AController(Pawn* pawn, ASprite* sprite)
	: d_pawn(pawn)
	, d_sprite(sprite)
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

} // end 
