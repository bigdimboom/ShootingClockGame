// clock_sprite.cpp
#include "clock_sprite.h"
#include "../engine/api/time.h"

namespace mygame
{

#define UNIT_DEGREE_SIX 6// const float unitDegree = 6.0; // (360 / 60)
#define UNIT_DEGREE_THIRTY 30 // 360 / 12

ClockSprite::ClockSprite(hctm::Point2f pos, float width, float height)
	: ASprite(pos)
	, d_clockFace(hctm::Point2f(pos.x() - width * 0.5f, pos.y() - height * 0.5f), width, height, 255, 0, 0)
	, d_hrHand(pos, pos + hctm::Point2f(0.0f, -1.0f) * 0.25f * height, 255, 204, 0)
	, d_minHand(pos, pos + hctm::Point2f(0.0f, -1.0f) * 0.40f * height, 255, 0, 128)
	, d_secHand(pos, pos + hctm::Point2f(0.0f, -1.0f)* 0.45f * height, 255, 255, 255)
	, d_prevHr(0)
	, d_prevMin(0)
	, d_prevSec(0)
{
}

ClockSprite::ClockSprite(const ClockSprite & other)
	: ASprite(d_pos)
	, d_clockFace(other.d_clockFace)
	, d_hrHand(other.d_hrHand)
	, d_minHand(other.d_minHand)
	, d_secHand(other.d_secHand)
	, d_prevHr(other.d_prevHr)
	, d_prevMin(other.d_prevMin)
	, d_prevSec(other.d_prevSec)

{
}

ClockSprite::ClockSprite(ClockSprite && other)
	: ASprite(std::move(d_pos))
	, d_clockFace(std::move(other.d_clockFace))
	, d_hrHand(std::move(other.d_hrHand))
	, d_minHand(std::move(other.d_minHand))
	, d_secHand(std::move(other.d_secHand))
	, d_prevHr(std::move(other.d_prevHr))
	, d_prevMin(std::move(other.d_prevMin))
	, d_prevSec(std::move(other.d_prevSec))
{
}

// ASSIGNMENT OVERLOADS
ClockSprite& ClockSprite::operator = (const ClockSprite & other)
{
	if (this != &other)
	{
		d_clockFace = other.d_clockFace;
		d_hrHand = other.d_hrHand;
		d_minHand = other.d_minHand;
		d_secHand = other.d_secHand;
		d_prevHr = other.d_prevHr;
		d_prevMin = other.d_prevMin;
		d_prevSec = other.d_prevSec;
	}
	return *this;
}

ClockSprite& ClockSprite::operator = (ClockSprite && other)
{
	if (this != &other)
	{
		d_clockFace = std::move(other.d_clockFace);
		d_hrHand = std::move(other.d_hrHand);
		d_minHand = std::move(other.d_minHand);
		d_secHand = std::move(other.d_secHand);
		d_prevHr = std::move(other.d_prevHr);
		d_prevMin = std::move(other.d_prevMin);
		d_prevSec = std::move(other.d_prevSec);
	}
	return *this;
}

// DESTRUCTOR
ClockSprite::~ClockSprite()
{
}

void ClockSprite::translate(float x, float y)
{
	d_pos += hctm::Point2f(x, y);
	d_clockFace.translate(x, y);
	d_hrHand.translate(x, y);
	d_minHand.translate(x, y);
	d_secHand.translate(x, y);
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
	d_clockFace.scale(factor);
	d_hrHand.scale(factor);
	d_minHand.scale(factor);
	d_secHand.scale(factor);
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
	int nowHr, nowMin, nowSec;
	GetTime(nowHr, nowMin, nowSec);

	int degreeSec = (nowSec - d_prevSec) * UNIT_DEGREE_SIX;
	int degreeMin = (nowMin - d_prevMin) * UNIT_DEGREE_SIX;
	int degreeHr = (nowHr - d_prevHr)   * UNIT_DEGREE_THIRTY;

	d_hrHand.rotate(d_pos, (float)degreeHr);
	d_minHand.rotate(d_pos, (float)degreeMin);
	d_secHand.rotate(d_pos, (float)degreeSec);

	d_prevHr = nowHr;
	d_prevMin = nowMin;
	d_prevSec = nowSec;
}

} // end namespace mygame