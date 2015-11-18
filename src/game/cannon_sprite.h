// cannon_sprite.h
#pragma once
#include "../engine/gameplay/asprite.h"
#include "../engine/rendering/drawable_triangle.h"

namespace mygame
{

class CannonSprite : public hctg::ASprite
{
private:
	hctr::DrawableTriangle d_tri;
public:
	// CONSTRUCTORS
	CannonSprite(hctm::Point2f pos);
	CannonSprite( const CannonSprite &);
	CannonSprite( CannonSprite &&);

	// ASSIGNMENT OVERLOADS
	CannonSprite& operator=(const CannonSprite &);
	CannonSprite& operator=(CannonSprite &&);

	// DESTRUCTOR
	~CannonSprite();

	// MEMBER FUNCTIONS
	void translate(float x, float y) override;
	void translate(hctm::Point2f increment) override;
	void rotate(const hctm::Point2f& pvt, float angleInDegree) override;
	void scale(float factor) override;
	float area() const override;

	void draw() override;
};

} //end namespace mygame