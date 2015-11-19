// line.h
#pragma once
#include "ishape.h"

namespace hctm
{

class Line : public IShape
{
protected:
	Point2f d_start;
	Point2f d_end;

public:
	// CONSTRUCTORS
	Line(Point2f start, Point2f right);
	Line(const Line & other);
	// copy constrctor.
	Line(Line && other);
	// move constrctor.

	// ASSIGNMENT OVERLOADS
	Line& operator = (const Line & other);
	// copy assignment.
	Line& operator = (Line && other);
	// move assignemnt.

	// DESTRUCTORS
	virtual ~Line();

	//ACCESSOR
	Point2f theStartPoint() const;
	Point2f theEndPoint() const;

	//MUTATORS
	void setPoints(Point2f start, Point2f end);

	// MEMBER FUCNTIONS
	void translate(float x, float y) override;
	void translate(Point2f increment) override;
	void rotate(const Point2f& pvt, float angleInDegree) override;
	void scale(float factor) override;
	float area() const override;
};

//ACCESSOR
inline
Point2f Line::theStartPoint() const
{
	return d_start;
}

inline
Point2f Line::theEndPoint() const
{
	return d_end;
}

//MUTATORS
inline
void Line::setPoints(Point2f start, Point2f end)
{
	d_start = start, d_end = end;
}

} // end namspace hctm - 20 mins

