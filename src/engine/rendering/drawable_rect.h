// drawable_rect.h
#pragma once
#include "idrawable.h"
#include "../math/rect.h"

namespace hctr
{

class DrawableRect : public hctm::Rect, public hctr::IDrawable
{
private:
	unsigned int d_r;
	unsigned int d_g;
	unsigned int d_b;
public:
	DrawableRect(const hctm::Point2f& topleft, float width, float height, 
				 unsigned int r, unsigned int g, unsigned int b);
	~DrawableRect();
	
	// MEMBER FUNCTIONS
	void setColor(unsigned int r, unsigned int g, unsigned int b);
	void draw() override;
};

} // end namespace hctr

