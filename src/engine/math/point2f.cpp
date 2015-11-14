// point2f.cpp
#include "point2f.h"
#include <assert.h>

namespace hctm
{

static const float k_PI = 3.1415926536f;
static const float DivideByZeroTolerance = float(1.0e-07);
static const float DegreesToRadians = k_PI / 180.0f;
// from "C_Application.cpp".  
// It is better to use macro to define them.

// ASSIGNMENT OVERLOAD
Point2f& Point2f::operator = (const Point2f & other)
{
	if (this != &other)
	{
		d_x = other.d_x;
		d_y = other.d_y;
	}
	return *this;
}

Point2f& Point2f::operator = (Point2f && other)
{
	if (this != &other)
	{
		d_x = std::move(other.d_x);
		d_y = std::move(other.d_y);
	}
	return *this;
}

// MEMBER FUNCTIONS
Point2f Point2f::operator - () const
{
	return Point2f(-d_x, -d_y);
}

Point2f Point2f:: operator + (const Point2f & vec) const
{
	return Point2f(d_x + vec.d_x, d_y + vec.d_y);
}

Point2f Point2f::operator - (const Point2f & point) const
{
	return Point2f(d_x - point.d_x, d_y - point.d_y);
}

Point2f Point2f::operator * (float scale) const
{
	return Point2f(d_x * scale, d_y * scale);
}

Point2f Point2f::operator * (const Point2f & other) const
{
	return Point2f(d_x * other.d_x, d_y * other.d_y);
}

Point2f Point2f:: operator / (float s) const
{
#ifdef _DEBUG
	assert(std::abs(s) < DivideByZeroTolerance);
#endif // _DEBUG
	float r = float(1.0) / s;
	return Point2f(d_x * r, d_y * r);
}

Point2f& Point2f::operator += (const Point2f& vec)
{
	d_x += vec.d_x;
	d_y += vec.d_y;
	return *this;
}

Point2f& Point2f::operator -= (const Point2f& pt)
{
	d_x -= pt.d_x;
	d_y -= pt.d_y;
	return *this;
}

Point2f& Point2f::operator *= (float s)
{
	d_x *= s;
	d_y *= s;
	return *this;
}

Point2f& Point2f::operator *= (const Point2f& other)
{
	d_x *= other.d_x;
	d_y *= other.d_y;
	return *this;
}

Point2f& Point2f::operator /= (float s)
{
#ifdef _DEBUG
	assert(std::abs(s) < DivideByZeroTolerance);
#endif // _DEBUG
	float r = float(1.0) / s;
	*this *= r;
	return *this;
}

// vector specific operations.
float Point2f::dot(const Point2f & other)
{
	return d_x * other.d_x + d_y * other.d_y;
}

float Point2f::length()
{
	return std::sqrt(d_x * d_x + d_y * d_y);
}

Point2f& Point2f::normalize()
{
	(*this) /= length();
	return *this;
}

void Point2f::rotate(const Point2f & pivot, float angleInDegree)
{
	// strickly speaking I should define a matrix class.
	// The solution is good enough for this project.
	float cosVal = cos(angleInDegree * DegreesToRadians);
	float sinVal = sin(angleInDegree * DegreesToRadians);

	float translateX = -pivot.x();
	float translateY = -pivot.y();

	float tmpX = d_x;
	float tmpY = d_y;

	d_x = ((tmpX + translateX) * cosVal - (tmpY + translateY) * sinVal) - translateX;
	d_y = ((tmpX + translateX) * sinVal + (tmpY + translateY) * cosVal) - translateY;
}


} // end namespace hctm - about 40 mins