// rect.cpp
#include "rect.h"

namespace hctm
{

// CONSTRUCTORS

Rect::Rect(const Point2f& topLeft, float width, float height)
	: d_topLeft(topLeft)
	, d_topRight(  d_topLeft.x() + width, d_topLeft.y())
	, d_downRight( d_topLeft.x() + width, d_topLeft.y() + height)
	, d_downLeft(  d_topLeft.x(), d_topLeft.y() + height)
{
}

Rect::Rect(float xLeftTop, float yLeftTop, float width, float height)
	: d_topLeft( Point2f(xLeftTop, yLeftTop))
	, d_topRight( d_topLeft.x() + width, d_topLeft.y() )
	, d_downRight( d_topLeft.x() + width, d_topLeft.y() + height)
	, d_downLeft( d_topLeft.x(), d_topLeft.y() + height)
{
}

Rect::Rect(const Rect & other)
	: d_topLeft(other.d_topLeft)
	, d_topRight(other.d_topRight)
	, d_downRight(other.d_downRight)
	, d_downLeft(other.d_downLeft)
{
}

Rect::Rect(Rect && other)
	: d_topLeft(std::move(other.d_topLeft))
	, d_topRight(std::move(other.d_topRight))
	, d_downRight(std::move(other.d_downRight))
	, d_downLeft(std::move(other.d_downLeft))
{
}

Rect& Rect::operator = (const Rect & other)
{
	if (this != &other)
	{
		d_topLeft = other.d_topLeft;
		d_topRight = other.d_topRight;
		d_downRight = other.d_downRight;
		d_downLeft = other.d_downLeft;
	}
	return *this;
}

Rect& Rect::operator = (Rect && other)
{
	if (this != &other)
	{
		d_topLeft = std::move(other.d_topLeft);
		d_topRight = std::move(other.d_topRight);
		d_downRight = std::move(other.d_downRight);
		d_downLeft = std::move(other.d_downLeft);
	}
	return *this;
}

//DESTRUCTOR
Rect::~Rect()
{
}

// MEMBER FUCNTIONS
void Rect::translate(float x, float y)
{
	Point2f increment(x, y);
	d_topLeft += increment;
	d_topRight += increment;
	d_downRight += increment;
	d_downLeft += increment;
}

void Rect::translate(Point2f increment)
{
	d_topLeft += increment;
	d_topRight += increment;
	d_downRight += increment;
	d_downLeft += increment;
}

void Rect::rotate(const Point2f& pvt, float angleInDegree)
{
	d_topLeft.rotate(pvt, angleInDegree);
	d_topRight.rotate(pvt, angleInDegree);
	d_downRight.rotate(pvt, angleInDegree);
	d_downLeft.rotate(pvt, angleInDegree);
}

void Rect::scale(float factor)
{
	// Again it should use matrix in regular situations.
	Point2f center = (d_downRight + d_topLeft) * 0.5f;
	// Point2f center = d_topLeft + vec;
	// translate to center
	d_topLeft -= center;
	d_topRight -= center;
	d_downRight -= center;
	d_downLeft -= center;
	// scale 
	d_topLeft *= factor;
	d_topRight *= factor;
	d_downRight *= factor;
	d_downLeft *= factor;
	// translate back
	d_topLeft += center;
	d_topRight += center;
	d_downRight += center;
	d_downLeft += center;
}

float Rect::area() const
{
	Point2f vec1 = d_topLeft - d_topRight;
	Point2f vec2 = d_downLeft - d_topLeft;
	float w = vec1.length();
	float h = vec2.length();
	return w * h;
}

float Rect::width() const
{
	Point2f vec1 = d_topLeft - d_topRight;
	return vec1.length();
}

float Rect::height() const
{
	Point2f vec2 = d_downLeft - d_topLeft;
	return vec2.length();
}

} // end namespace hctm

#ifdef UNIT_TEST

void UTEST()
{
	//tested in C_Application
}

#endif // end of unit test