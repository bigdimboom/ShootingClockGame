// pawn.h
#pragma once
#include "../scene/actor.h"
#include "../scene/itickable.h"
// a pawn is a actor that 
// can be processed by a controller.
// controller doesn't responsible for deleteing controller's memory


namespace hctg
{

class Pawn : public hcts::Actor, public hcts::ITickable
{
protected:
	hctm::Point2f d_vel;
public:
	// CONSTRUCTORS
	Pawn(hctm::Point2f pos = hctm::Point2f(0.0f, 0.0f),
		 hctm::Point2f vel = hctm::Point2f(0.0f, 0.0f));
	// default constructors.

	Pawn(const Pawn & other);
	Pawn(Pawn && other);

	// ASSIGNMENT OVERLOADS
	Pawn& operator = (const Pawn & other);
	Pawn& operator = (Pawn && other);

	// DESTRUCTOR
	virtual ~Pawn();

	// ACCESSOR 
	hctm::Point2f velocity() const;

	// MUTATOR
	void setVelocity(hctm::Point2f velocity);

	// MEMBER FUNCTIONS
	virtual void preTick() override;
	virtual void tick() override;
	virtual void postTick() override;
};

} // end namespace hctg