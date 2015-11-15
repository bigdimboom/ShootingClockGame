// drawable_rect.cpp
#include "drawable_rect.h"
#include "../api/graphics.h"

namespace hctr
{

DrawableRect::DrawableRect(const hctm::Point2f& topleft, float width, float height,
						   unsigned int r, unsigned int g, unsigned int b)
						   : Rect(topleft, width, height)
						   , d_r(r)
						   , d_g(g)
						   , d_b(b)
{
}

DrawableRect::~DrawableRect()
{

}

void DrawableRect::setColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_r = r;
	d_g = g;
	d_b = b;
}

void DrawableRect::draw()
{
	unsigned int color = GetRGB(d_r, d_g, d_b);

	DrawLine((int)d_topLeft.x(), (int)d_topLeft.y(), (int)d_topRight.x(), (int)d_topRight.y(), color);
	DrawLine((int)d_topRight.x(), (int)d_topRight.y(), (int)d_downRight.x(), (int)d_downRight.y(), color);
	DrawLine((int)d_downRight.x(), (int)d_downRight.y(), (int)d_downLeft.x(), (int)d_downLeft.y(), color);
	DrawLine((int)d_downLeft.x(), (int)d_downLeft.y(), (int)d_topLeft.x(), (int)d_topLeft.y(), color);
}

} // end namespace hctr

#ifdef UNIT_TEST

void useInput()
{
	if (key  & s_KeyUp)
	{
		d_rec.translate(0.0, -5.0f);
	}
	if (key  & s_KeyDown)
	{
		d_rec.translate(0.0, 5.0f);
	}
	if (key  & s_KeyLeft)
	{
		d_rec.translate(-5.0, 0.0f);
	}
	if (key  & s_KeyRight)
	{
		d_rec.translate(5.0, 0.0f);
	}
}

void draw()
{
	d_rec.draw();
}

#endif // end of unit test