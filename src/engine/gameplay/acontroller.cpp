// acontroller.cpp
#include "acontroller.h"
#include <assert.h>

namespace hctg
{

// CONSTRUCTORS
AController::AController(Pawn* pawn)
	:d_pawn(pawn)
{
}

// DESTRUCTOR
AController::~AController()
{
}


void AController::addPawn(Pawn* pawn)
{
	assert(pawn);
	d_pawn = pawn;
}

void AController::removePawn()
{
	d_pawn = nullptr;
}

} // end 
