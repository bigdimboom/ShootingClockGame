// actor.h
#pragma once
#include "../math/point2f.h"


namespace hcts
{
// an actor can be placed in a scene.
// speed and position is its properties.
// Of course, I can define a IPhysics layer and sperate Phys and Actor
//, defining different Phys properties, e.g. vel, accelation...
// For this project, there is no static objects in the scene. So... 
class Actor
{
protected:
	hctm::Point2f d_pos;
public:
	//COSTRUCTOS
	Actor(hctm::Point2f pos = hctm::Point2f(0.0f,0.0f));
	Actor(const Actor & actor);
	Actor(Actor && actor);

	// ASSIGNMENT OVERLOADS
	Actor& operator = (const Actor &);
	Actor& operator = (Actor &&);

	//DESTRUCTOR
	virtual ~Actor();

	//ACCESSORS
	hctm::Point2f positionXY() const;

	//MUTATORS
	void setPosition(hctm::Point2f pos);
	  // set d_pos to pos
	void translate(hctm::Point2f deltaPos);
	 // add d_pos by deltaPos.
};

} // end namespace hcts - 20 mins