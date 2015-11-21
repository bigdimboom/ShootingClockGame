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

	// MUTATORS
	void setPostion(hctm::Point2f pos) override;
	void setColor(unsigned int r, unsigned int g, unsigned int b);

	// MEMBER FUNCTIONS
	void translate(float x, float y) override;
	void translate(hctm::Point2f increment) override;
	void rotate(const hctm::Point2f& pvt, float angleInDegree) override;
	void scale(float factor) override;
	float area() const override;

	void draw() override;
};

// MUTATORS
inline
void CannonSprite::setPostion(hctm::Point2f pos)
{
	auto old = d_pos;
	d_pos = pos;
	auto incr = d_pos - old;
	d_tri.translate(incr);
}

inline
void CannonSprite::setColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_tri.setColor(r, g, b);
}

} //end namespace mygame