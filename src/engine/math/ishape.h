// ishape.cpp
#pragma once
#include "point2f.h"

namespace hctm
{

class IShape
{
public:
	virtual ~IShape(){}

	virtual void translate(float x, float y) = 0; 
	  // move shape x by x, y by y.
	virtual void translate(Point2f increment) = 0; 
	  // move shape x by x, y by y.
	virtual void rotate(const Point2f& pvt, float angleInDegree) = 0; 
	  // rotate around some point by some angle in degree.
	virtual void scale(float factor) = 0; 
	  // scale up or down shape by some factor.
	virtual float area() const = 0;
	  // this can be handy if you want to know the ratio of shapeArea() : ScreenArea().
};

} // end namespace hctm
