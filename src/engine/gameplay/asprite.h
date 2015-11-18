// asprite.h
#pragma once
// 2D visual representations
#include "../math/ishape.h"
#include "../rendering/idrawable.h"
#include <vector>

namespace hctg
{

class ASprite : public hctm::IShape, public hctr::IDrawable
{
public:
	ASprite(){}
	~ASprite(){}

	// MEMBER FUNCTIONS
	virtual void translate(float x, float y) = 0;
	virtual void translate(hctm::Point2f increment) = 0;
	virtual void rotate(const hctm::Point2f& pvt, float angleInDegree) = 0;
	virtual void scale(float factor) = 0;
	virtual float area() const = 0;
	virtual void draw() = 0;
};

} // end namespace hctg