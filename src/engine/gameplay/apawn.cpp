// pawn.cpp
#include "apawn.h"

namespace hctg
{

// CONSTRUCTOR
APawn::APawn(AController* controller)
	: d_controller(controller)
{
}

// DESTRUCTOR
APawn::~APawn()
{
}

// ACCESSOR
AController* APawn::controller()
{
	return d_controller;
}

// MUTATOR
void APawn::setController(AController* controller)
{
	d_controller = controller;
}

void APawn::removeController()
{
	d_controller = nullptr;
}

} // end namespace hctg