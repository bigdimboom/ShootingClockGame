// asprite.h
#pragma once
// 2D visual representations
#include "../math/ishape.h"
#include "../math/point2f.h"
#include "../rendering/idrawable.h"

namespace hctg
{

class ASprite : public hctm::IShape, public hctr::IDrawable
{
protected:
	hctm::Point2f d_pos; // cneter

private:
	// DELETED
	ASprite(const ASprite &) = delete;
	ASprite(ASprite &&) = delete;
	ASprite& operator = (const ASprite &) = delete;
	ASprite& operator = (ASprite &&) = delete;

public:
	// CONSTRUCTOR
	ASprite(hctm::Point2f pos = hctm::Point2f(0.0f,0.0f));

	// DESTRUCTOR
	virtual ~ASprite();

	//ACCESSOR
	hctm::Point2f position() const;

	//MUTATORS
	void setPostion(hctm::Point2f pos);

	// MEMBER FUNCTIONS
	virtual void translate(float x, float y) override = 0;
	virtual void translate(hctm::Point2f increment) override = 0;
	virtual void rotate(const hctm::Point2f& pvt, float angleInDegree) override = 0;
	virtual void scale(float factor) override = 0;
	virtual float area() const override = 0;
	virtual void draw() override = 0;
};

} // end namespace hctg