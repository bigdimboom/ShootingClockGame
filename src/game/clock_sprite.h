// clock_sprite.h
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
	// copy constructors.
	ClockSprite(ClockSprite &&);
	// move constructor.

	// ASSIGNMENT OVERLOADS
	ClockSprite& operator= (const ClockSprite &);
	// copy assignment.
	ClockSprite& operator= (ClockSprite &&);
	// move assignment.  

	// MUTATORS
	void setClockFaceColor(unsigned int r, unsigned int g, unsigned int b);
	void setHrColor(unsigned int r, unsigned int g, unsigned int b);
	void setMinColor(unsigned int r, unsigned int g, unsigned int b);
	void setSecColor(unsigned int r, unsigned int g, unsigned int b);

	void setPostion(hctm::Point2f pos) override;

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
	void postTick() override;

	// Non-class function
	friend std::ostream& operator<<(std::ostream& stream, const ClockSprite &);
};

// NON-CLASS FUNCTIONS
inline
std::ostream& operator<<(std::ostream& stream, const ClockSprite & obj)
{
	return stream
		<< "Hr: " << obj.d_prevHr
		<< "Min: " << obj.d_prevMin
		<< "Sec:" << obj.d_prevSec;
}


// MUTATORS
inline
void ClockSprite::setClockFaceColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_clockFace.setColor(r,g,b);
}

inline
void ClockSprite::setHrColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_hrHand.setColor(r, g, b);
}

inline
void ClockSprite::setMinColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_minHand.setColor(r, g, b);
}

inline
void ClockSprite::setSecColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_secHand.setColor(r, g, b);
}

inline
void ClockSprite::setPostion(hctm::Point2f pos)
{
	auto old = d_pos;
	d_pos = pos;
	auto incr = d_pos - old;
	d_clockFace.translate(incr);
	d_hrHand.translate(incr);
	d_minHand.translate(incr);
	d_secHand.translate(incr);
}
} // end namespace mygame