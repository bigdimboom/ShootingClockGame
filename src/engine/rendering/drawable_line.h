#pragma once
#include "../math/line.h"
#include "idrawable.h"

namespace hctr
{

class DrawableLine : public hctm::Line, public IDrawable
{
private:
	unsigned int d_r;
	unsigned int d_g;
	unsigned int d_b;
public:
	DrawableLine(const hctm::Point2f& start, const hctm::Point2f& end,
				 unsigned int r, unsigned int g, unsigned int b);
	~DrawableLine();

	// MEMBER FUNCTIONS
	void setColor(unsigned int r, unsigned int g, unsigned int b);
	void draw() override;
};

} // end namespace hctr