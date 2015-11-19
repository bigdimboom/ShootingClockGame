#pragma once
#include "../math/rect.h"

namespace hctc
{

class Aabb : public hctm::Rect
{
private:
	using Rect::rotate; // delete roate function
	Aabb(const Aabb & other) = delete;
	Aabb(Aabb && other) = delete;
	Aabb& operator = (const Aabb&) = delete;
	Aabb& operator = (Aabb&&) = delete;
public:
	// CONSTRUCTORS
	Aabb(const hctm::Point2f& topLeft, float width, float height);
	Aabb(float xLeftTop, float yLeftTop, float width, float height);

	// DESTRUCTORS
	~Aabb();
	
	// ACCESSORS
	hctm::Point2f topLeftPoint() const;
	hctm::Point2f downRightPoint() const;

	// MEMBER FUNCTIONS
	bool doesCollide(const Aabb & aabb);

};

// CONSTRUCTORS
inline
Aabb::Aabb(const hctm::Point2f& topLeft, float width, float height)
: Rect(topLeft, width, height)
{
}

inline
Aabb::Aabb(float xLeftTop, float yLeftTop, float width, float height)
: Rect(xLeftTop, yLeftTop, width, height)
{
}

// DESTRUCTORS
inline
Aabb::~Aabb()
{
}

// ACCESSORS
inline
hctm::Point2f Aabb::topLeftPoint() const
{
	return d_topLeft;
}

inline
hctm::Point2f Aabb::downRightPoint() const
{
	return d_downRight;
}

// MEMBER FUNCTIONS
inline
bool Aabb::doesCollide(const Aabb & candidate)
{
	return 
	 !(d_downRight.x() < candidate.d_topLeft.x() ||
	  candidate.d_downRight.x() < d_topLeft.x() ||
	  d_downRight.y() < candidate.d_topLeft.y() ||
	  candidate.d_downRight.y() < d_topLeft.y() );
}

} // end namespace hctc - c for collision

