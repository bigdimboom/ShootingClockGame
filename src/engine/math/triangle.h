// triangle.h
#pragma once
#include "ishape.h"

namespace hctm
{

class Triangle : public IShape
{
private:
	Point2f d_top;
	Point2f d_left;
	Point2f d_right;

	Triangle() = delete;

public:
	// CONSTRUCTORS
	Triangle(Point2f top, Point2f left, Point2f right);
	Triangle(const Triangle & other);
	  // copy constrctor.
	Triangle(Triangle && other);
	  // move constrctor.

	// ASSIGNMENT OVERLOADS
	Triangle& operator = (const Triangle & other);
	  // copy assignment.
	Triangle& operator = (Triangle && other);
	  // move assignemnt.

	// DESTRUCTORS
	~Triangle();

	// MEMBER FUCNTIONS
	void translate(float x, float y) override;
	void translate(Point2f increment) override;
	void rotate(const Point2f& pvt, float angleInDegree) override;
	void scale(float factor) override;
	float area() const override;
};

} // end namspace hctm - 20 mins
