// drawable_triangle.cpp
#include "drawable_triangle.h"
#include "../api/graphics.h"

namespace hctr
{

DrawableTriangle::DrawableTriangle(const hctm::Point2f& top, const hctm::Point2f& left, const hctm::Point2f& right,
						   unsigned int r, unsigned int g, unsigned int b)
						   : Triangle(top, left, right)
						   , d_r(r)
						   , d_g(g)
						   , d_b(b)
{
}


DrawableTriangle::~DrawableTriangle()
{
}

void DrawableTriangle::setColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_r = r;
	d_g = g;
	d_b = b;
}

void DrawableTriangle::draw()
{
	unsigned int color = GetRGB(d_r, d_g, d_b);

	DrawLine((int)d_top.x(), (int)d_top.y(), (int)d_right.x(), (int)d_right.y(), color);
	DrawLine((int)d_right.x(), (int)d_right.y(), (int)d_left.x(), (int)d_left.y(), color);
	DrawLine((int)d_left.x(), (int)d_left.y(), (int)d_top.x(), (int)d_top.y(), color);
}

} // end namespace hctr