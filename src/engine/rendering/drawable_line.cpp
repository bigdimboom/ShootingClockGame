// drawable_line.cpp
#include "drawable_line.h"
#include "../api/graphics.h"

namespace hctr
{

DrawableLine::DrawableLine(const hctm::Point2f& start, const hctm::Point2f& end,
						   unsigned int r, unsigned int g, unsigned int b)
						   : Line(start, end)
						   , d_r(r)
						   , d_g(g)
						   , d_b(b)
{
}


DrawableLine::~DrawableLine()
{
}

void DrawableLine::setColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_r = r;
	d_g = g;
	d_b = b;
}

void DrawableLine::draw()
{
	unsigned int color = GetRGB(d_r, d_g, d_b);

	DrawLine((int)d_start.x(), (int)d_start.y(), (int)d_end.x(), (int)d_end.y(), color);
}

} // end namespace hctr