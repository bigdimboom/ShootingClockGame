// drawable_triangle.h
#pragma once
#include "idrawable.h"
#include "../math/triangle.h"

namespace hctr
{

class DrawableTriangle : public hctm::Triangle, public hctr::IDrawable
{
private:
	unsigned int d_r;
	unsigned int d_g;
	unsigned int d_b;
public:
	DrawableTriangle(const hctm::Point2f& pt1, const hctm::Point2f& pt2, const hctm::Point2f& pt3,
				 unsigned int r, unsigned int g, unsigned int b);
	~DrawableTriangle();

	// MEMBER FUNCTIONS
	void setColor(unsigned int r, unsigned int g, unsigned int b);
	void draw() override;
};

} // end namespace hctr