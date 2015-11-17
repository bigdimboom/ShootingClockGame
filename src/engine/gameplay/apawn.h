// pawn.h
#pragma once
#include "../scene/actor.h"
#include "../scene/itickable.h"
#include "acontroller.h"
// a pawn is a actor that 
// can be processed by a controller.
// controller doesn't responsible for deleteing controller's memory


namespace hctg
{

class APawn : public hcts::Actor, public hcts::ITickable
{
protected:
	AController* d_controller;

	// DELETED
	APawn(const APawn & other) = delete;
	APawn(APawn && other) = delete;
	APawn& operator = (const APawn & other) = delete;
	APawn& operator = (APawn && other) = delete;

public:
	// CONSTRUCTORS
	APawn(AController* controller = nullptr);
	  // default constructors.

	// DESTRUCTOR
	~APawn();

	// ACCESSOR 
	AController* controller();

	// MUTATOR
	void setController(AController* controller);
	void removeController();

	// MEMBER FUNCTIONS
	virtual void preTick() = 0;
	virtual void tick() = 0;
};

} // end namespace hctg