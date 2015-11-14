// point2.h
#pragma once
#include <cmath>
#include <memory>
#include <iostream>

namespace hctm // hangar coding test math
{

class Point2f
{
private:
	float d_x;
	float d_y;

public:
	// CONSTRUCTORS
	Point2f(float x = 0.0f, float y=0.0f);
	// default constructor.
	Point2f(const Point2f & other);
	// copy constructor.
	Point2f(Point2f && other);

	// DESTRUCTOR
	~Point2f();

	// ACCESSORS
	float x() const;
	float y() const;

	// MUTATORS
	void setX(float x);
	void setY(float y);

	// ASSIGNMENT OVERLOAD
	Point2f& operator = (const Point2f & other);
	  // copy assignment.
	Point2f& operator = (Point2f && other);
	  // move assignment.

	// MEMBER FUNCTIONS
	Point2f operator - () const;
	  // unary minus operator, negate all elements.
	Point2f operator + (const Point2f & vector) const;
	  // element wise addition (affine combination, getting a point)
	Point2f operator - (const Point2f & point) const;
	  // element wise subtraction (two points getting a line).
	Point2f operator * (float scale) const;
	  // elements are multiplied by the scale.
	Point2f operator * (const Point2f & other) const;
	  // element wise multiplication.

	Point2f operator / (float s) const;
	  // s must not be equal to zero.
	Point2f& operator += (const Point2f& vec);
	  // addition on current object.
	Point2f& operator -= (const Point2f& pt);
	  // subtraction on current object.
	Point2f& operator *= (float s);
	  // scale on current object.
	Point2f& operator *= (const Point2f& other);
	  // multiplication on current object.
	Point2f& operator /= (float s);
	  // division on current object.

	// vector specific operations.
	float dot(const Point2f & other);
	  // dot product if it is a vector.
	float length();
	  // get the length if it is a vector;
	Point2f& normalize();
	  // nomalize it if it is vector

	void rotate(const Point2f & pivot, float angleInDegree);
	  // rotate around the pivot point by some angle.

	// NON-CLASS FUNCTIONS
	friend std::ostream& operator<<(std::ostream& stream, const Point2f& obj);

};

// NON-CLASS FUNCTIONS
inline
std::ostream& operator<<(std::ostream& stream, const Point2f& obj)
{
	return stream << "x: " << obj.d_x << "y: " << obj.d_y;
}


// CONSTRUCTORS
inline
Point2f::Point2f(float x, float y)
: d_x(x), d_y(y)
{
}

inline
Point2f::Point2f(const Point2f & other)
:d_x(other.d_x), d_y(other.d_y)
{
}

inline
Point2f::Point2f(Point2f && other)
: d_x(std::move(other.d_x)), d_y(std::move(other.d_y))
{
}

// DESTRUCTOR
inline
Point2f::~Point2f()
{
}

// ACCESSORS

inline
float Point2f::x() const
{
	return d_x;
}


inline
float Point2f::y() const
{
	return d_y;
}

// MUTATORS
inline
void Point2f::setX(float x)
{
	d_x = x;
}

inline
void Point2f::setY(float y)
{
	d_y = y;
}

} // end namespace hctm

