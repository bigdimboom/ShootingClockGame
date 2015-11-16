// rect.h
#pragma once
#include "ishape.h"

namespace hctm
{

class Rect : public IShape
{
protected:
	Point2f d_topLeft;
	  // top left point.
	Point2f d_topRight;
	  // top right point.
	Point2f d_downRight;
	  // down right point.
	Point2f d_downLeft;
	  // down left point.
public:
	// CONSTRUCTORS
	Rect(const Point2f& topLeft, float width, float height);
	  // initiate rectangle from top left corner.
	Rect(float xLeftTop, float yLeftTop, float width, float height);
	  // initiate rectangle from top left corner.
	Rect(const Rect & other);
	  // copy constrctor.
	Rect(Rect && other);
	  // move constrctor.

	// ASSIGNMENT OVERLOADS
	Rect& operator = (const Rect & other);
	  // copy assignment.
	Rect& operator = (Rect && other);
	  // move assignemnt.

	// DESTRUCTORS
	~Rect();

	// MEMBER FUCNTIONS
	virtual void translate(float x, float y) override;
	virtual void translate(Point2f increment) override;
	virtual void rotate(const Point2f& pvt, float angleInDegree) override; // aabb doesn't need rotate.
	void scale(float factor) override;
	float area() const override;

	float width() const;
	float height() const;
};

} // end namespace hctm - about 1 hour