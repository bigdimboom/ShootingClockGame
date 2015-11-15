// triangle.cpp
#include "triangle.h"
#include <iostream>

namespace hctm
{

// CONSTRUCTORS
Triangle::Triangle(Point2f top, Point2f left, Point2f right)
	: d_top(top)
	, d_left(left)
	, d_right(right)
{
}

Triangle::Triangle(const Triangle & other)
	: d_top(other.d_top)
	, d_left(other.d_left)
	, d_right(other.d_right)
{
}

Triangle::Triangle(Triangle && other)
	: d_top(std::move(other.d_top))
	, d_left(std::move(other.d_left))
	, d_right(std::move(other.d_right))
{
}


// ASSIGNMENT OVERLOADS
Triangle& Triangle::operator = (const Triangle & other)
{
	if (this != &other)
	{
		d_top = other.d_top;
		d_left = other.d_left;
		d_right = other.d_right;
	}
	return *this;
}

Triangle& Triangle::operator = (Triangle && other)
{
	if (this != &other)
	{
		d_top = std::move(other.d_top);
		d_left = std::move(other.d_left);
		d_right = std::move(other.d_right);
	}
	return *this;
}

// DESTRUCTORS
Triangle::~Triangle()
{
}

// MEMBER FUCNTIONS
void Triangle::translate(float x, float y)
{
	Point2f incre(x,y);
	d_top += incre;
	d_left += incre;
	d_right += incre;
}

void Triangle::translate(Point2f increment)
{
	d_top += increment;
	d_left += increment;
	d_right += increment;
}

void Triangle::rotate(const Point2f& pvt, float angleInDegree)
{
	d_top.rotate(pvt, angleInDegree);
	d_left.rotate(pvt, angleInDegree);
	d_right.rotate(pvt, angleInDegree);
}

void Triangle::scale(float factor)
{
	// no implementations.
#ifdef _DEBUG
	std::cerr << "No scale method for a general triangle." << std::endl;
#endif // _DEBUG
}

float Triangle::area() const
{
	return
		(d_top.x() *  (d_left.y() - d_right.y()) +
		d_left.x() * (d_right.y() - d_top.y()) +
		d_right.x() * (d_top.y() - d_left.y())) * 0.5f;
}

} // end namespace hctm