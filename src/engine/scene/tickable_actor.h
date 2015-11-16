// tickable_actor.h
#pragma once
#include "itickable.h"
#include "actor.h"

// I thought about adding d_velocity to Actor class, its parent class.
// But what if it is static object in the scene, it would be wast 2 floating-size memory.
// Only need d_velocity after time variables comming in.

namespace hcts
{
class TickableActor : public Actor, public ITickable
{
protected:
	hctm::Point2f d_vel;
public:
	// CONSTRUCTORS
	TickableActor(hctm::Point2f position, hctm::Point2f velocity);
	TickableActor(const TickableActor &);
	TickableActor(TickableActor &&);

	// ASSIGNMENT OVERLOADS
	TickableActor& operator = (const TickableActor &);
	TickableActor& operator = (TickableActor &&);

	// DESTRUCTOR
	~TickableActor();

	// ACCESSORS
	hctm::Point2f velocity() const; 

	// MUTATORS
	void setVelocity(hctm::Point2f vel);
	  // set velocity to vel
	void addToVelocity(hctm::Point2f deltaV);
	  // increment velocity by deltaV
	
	// CONSTANTS
	static const int K_VEL_MIN_INCREMENT = 10;

	// MEMBER FUNCTIONS
	virtual void preTick() override;
	virtual void tick() override;

};

} // end namespace hcts - 20 mins
