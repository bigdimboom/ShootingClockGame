// bullet.cpp
#include "bullet_sprite.h"

namespace mygame
{

BulletSprite::BulletSprite(hctm::Point2f pos, hctm::Point2f direction)
	: ASprite(pos)
	, d_bullet(pos, pos + direction, 255, 255, 255)
{
}


BulletSprite::BulletSprite(const BulletSprite & other)
	: ASprite(other.d_pos)
	, d_bullet(other.d_bullet)
{
}

BulletSprite::BulletSprite(BulletSprite && other)
	: ASprite(std::move(other.d_pos))
	, d_bullet(std::move(other.d_bullet))
{
}

// ASSIGNMENT OVERLOADS
BulletSprite& BulletSprite::operator = (const BulletSprite & other)
{
}

BulletSprite& BulletSprite::operator = (const BulletSprite && other)
{
}

// DESTRUCTOR
BulletSprite::~BulletSprite()
{
}

// MEMBER FUNCTIONS
void BulletSprite::translate(float x, float y)
{
	d_bullet.translate(x, y);
}

void BulletSprite::translate(hctm::Point2f increment)
{
	d_bullet.translate(increment);
}

void BulletSprite::rotate(const hctm::Point2f& pvt, float angleInDegree)
{
	d_bullet.rotate(pvt, angleInDegree);
}

void BulletSprite::scale(float factor)
{
	d_bullet.scale(factor);
}

float BulletSprite::area() const
{
	return d_bullet.area();
}

void BulletSprite::draw()
{
	d_bullet.draw();
}

} // end namespace mygame