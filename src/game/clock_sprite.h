#pragma once
#include "../engine/gameplay/asprite.h"
#include "../engine/rendering/drawable_rect.h"
#include "../engine/rendering/drawable_line.h"
#include "../engine/scene/itickable.h"

namespace mygame
{

class ClockSprite : public hctg::ASprite, public hcts::ITickable
{
private:
	hctr::DrawableRect d_clockFace;
	hctr::DrawableLine d_hrHand;
	hctr::DrawableLine d_minHand;
	hctr::DrawableLine d_secHand;

	int d_prevHr;
	int d_prevMin;
	int d_prevSec;

public:
	// CONSTRUCTORS
	ClockSprite(hctm::Point2f pos, float width = 100.0f, float height = 100.0f);
	  // default constructor.
	ClockSprite(const ClockSprite &);
	  // copy constructor.
	ClockSprite(ClockSprite &&);
	  // move constructor.

	// ASSIGNMANET OVERLOADS
	ClockSprite& operator = (const ClockSprite &);
	ClockSprite& operator = ( ClockSprite &&);

	// DESTRUCTOR
	~ClockSprite();

	// MEMBER FUNCTIONS
	void translate(float x, float y) override;
	void translate(hctm::Point2f increment) override;
	void rotate(const hctm::Point2f& pvt, float angleInDegree) override;
	void scale(float factor) override;
	float area() const override;

	void draw() override;

	void preTick() override;
	void tick() override;

};

} // end namespace mygame