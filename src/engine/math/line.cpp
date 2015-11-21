// line.cpp
#include "line.h"
#include <iostream>

namespace hctm
{

// CONSTRUCTORS
Line::Line(Point2f start, Point2f right)
	: d_start(start)
	, d_end(right)
{
}

Line::Line(const Line & other)
	: d_start(other.d_start)
	, d_end(other.d_end)
{
}

Line::Line(Line && other)
	: d_start(std::move(other.d_start))
	, d_end(std::move(other.d_end))
{
}

// ASSIGNMENT OVERLOADS
Line& Line::operator = (const Line & other)
{
	if (this != &other)
	{
		d_start = other.d_start;
		d_end = other.d_end;
	}
	return *this;
}

Line& Line::operator = (Line && other)
{
	if (this != &other)
	{
		d_start = std::move(other.d_start);
		d_end = std::move(other.d_end);
	}
	return *this;
}

// DESTRUCTORS
Line::~Line()
{
}

// MEMBER FUCNTIONS
void Line::translate(float x, float y)
{
	Point2f increment(x, y);
	d_start += increment;
	d_end += increment;
}

void Line::translate(Point2f increment)
{
	d_start += increment;
	d_end += increment;
}

void Line::rotate(const Point2f& pvt, float angleInDegree)
{
	d_start.rotate(pvt, angleInDegree);
	d_end.rotate(pvt, angleInDegree);
}

void Line::scale(float factor)
{
	Point2f center = (d_start + d_end) * 0.5f;
	//translate to (0,0)
	d_start -= center;
	d_end -= center;
	//scale.
	d_start *= factor;
	d_end *= factor;
	// translate back.
	d_start += center;
	d_end += center;
}

float Line::area() const 
{
#ifdef _DEBUG
	std::cerr << "A line has no area.\n";
#endif
	return 0.0f;
}

} // end namespace hctm