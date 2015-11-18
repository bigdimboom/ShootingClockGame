// cannon_sprite.cpp
#include "cannon_sprite.h"

namespace mygame
{
// CONSTRUCTORS
CannonSprite::CannonSprite(hctm::Point2f pos)
	: ASprite(pos)
	, d_tri(hctm::Point2f(pos.x(), pos.y() - 30),
			hctm::Point2f(pos.x() - 10, pos.y()),
			hctm::Point2f(pos.x() + 10, pos.y()),
			0, 0, 255)
{
}

CannonSprite::CannonSprite(const CannonSprite & other)
	: ASprite(other.d_pos)
	, d_tri(other.d_tri)
{
}

CannonSprite::CannonSprite(CannonSprite && other)
	: ASprite(std::move(other.d_pos))
	, d_tri(std::move(other.d_tri))
{
}

// ASSIGNMENT OVERLOADS
CannonSprite& CannonSprite::operator = (const CannonSprite & other)
{
	if (this != &other)
	{
		d_pos = other.d_pos;
		d_tri = other.d_tri;
	}
	return *this;
}

CannonSprite& CannonSprite::operator = (CannonSprite && other)
{
	if (this != &other)
	{
		if (this != &other)
		{
			d_pos = std::move(other.d_pos);
			d_tri = std::move(other.d_tri);
		}
		return *this;
	}
	return *this;
}

// DESTRUCTOR
CannonSprite::~CannonSprite()
{
}

// MEMBER FUNCTIONS
void CannonSprite::translate(float x, float y)
{
	d_tri.translate(x, y);
}

void CannonSprite::translate(hctm::Point2f increment)
{
	d_tri.translate(increment);
}

void CannonSprite::rotate(const hctm::Point2f& pvt, float angleInDegree)
{
	d_tri.rotate(pvt, angleInDegree);
}

void CannonSprite::scale(float factor)
{
	d_tri.scale(factor);
}

float CannonSprite::area() const
{
	return d_tri.area();
}

void CannonSprite::draw()
{
	d_tri.draw();
}

} //end namespace mygame