// aabb.cpp
#include "aabb.h"

namespace hctc
{

// MUTATOR
void Aabb::setPosition(hctm::Point2f pos)
{
	hctm::Point2f old = getCenter();
	hctm::Point2f incr = pos - old;
	translate(incr);
}

}