// actor.h
#pragma once
#include "../math/point2f.h"

namespace hcts
{

class Actor
{
private:
	hctm::Point2f d_pos;
public:
	//COSTRUCTOS
	Actor(hctm::Point2f pos);
	Actor(const Actor & actor);
	Actor(Actor && actor);

	// ASSIGNMENT OVERLOADS
	Actor& operator = (const Actor &);
	Actor& operator = (Actor &&);

	//DESTRUCTOR
	~Actor();

	//ACCESSORS
	hctm::Point2f positionXY() const;

	//MUTATORS
	void set(hctm::Point2f pos);
	  // set d_pos to pos
	void translate(hctm::Point2f deltaPos);
	 // add d_pos by deltaPos.
};

} // end namespace hcts