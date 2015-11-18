#include "clock_sprite.h"

namespace mygame
{

ClockSprite::ClockSprite(hctm::Point2f pos, float width, float height)
	: ASprite(pos)
	, d_clockFace( hctm::Point2f( pos.x() - width / 2.0f, pos.y() - height/ 2.0f), width, height, 255, 0, 0)
	, d_hrHand(pos, hctm::Point2f(0.0f,1.0f) * 0.9f * height, 255, 204, 0)
	, d_minHand(pos, hctm::Point2f(0.0f, 1.0f) * 0.6f * height, 255, 0, 128)
	, d_secHand(pos, hctm::Point2f(0.0f, 1.0f)* 0.3f * height, 255, 255, 255)
{
}


ClockSprite::~ClockSprite()
{
}

void ClockSprite::translate(float x, float y)
{
	d_pos += hctm::Point2f(x, y);
	d_clockFace.translate(x,y);
	d_hrHand.translate(x,y);
	d_minHand.translate(x,y);
	d_secHand.translate(x,y);
}

void ClockSprite::translate(hctm::Point2f increment)
{
	d_pos += increment;
	d_clockFace.translate(increment);
	d_hrHand.translate(increment);
	d_minHand.translate(increment);
	d_secHand.translate(increment);
}

void ClockSprite::rotate(const hctm::Point2f& pvt, float angleInDegree)
{
	// Do nothing
}

void ClockSprite::scale(float factor)
{
	d_clockFace.translate(factor);
	d_hrHand.translate(factor);
	d_minHand.translate(factor);
	d_secHand.translate(factor);
}

float ClockSprite::area() const
{
	return d_clockFace.area();
}

void ClockSprite::draw()
{
	d_clockFace.draw();
	d_hrHand.draw();
	d_minHand.draw();
	d_secHand.draw();
}

void ClockSprite::preTick()
{
}

void ClockSprite::tick()
{
}

} // end namespace mygame