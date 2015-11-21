// bullet_sprite.h
#pragma once
#include "../engine/gameplay/asprite.h"
#include "../engine/rendering/drawable_line.h"

namespace mygame
{

class BulletSprite : public hctg::ASprite
{
private:
	hctr::DrawableLine d_bullet;
public:
	// CONSTRUCTORS
	BulletSprite(hctm::Point2f pos, hctm::Point2f direction);
	BulletSprite(const BulletSprite &);
	BulletSprite(BulletSprite &&);

	// ASSIGNMENT OVERLOADS
	BulletSprite& operator = (const BulletSprite &);
	BulletSprite& operator = (const BulletSprite &&);

	// DESTRUCTOR
	~BulletSprite();

	// MUTATORS
	void setPostion(hctm::Point2f pos) override;
	void setColor(unsigned int r, unsigned int g, unsigned int b);

	// MEMBER FUNCTIONS
	void translate(float x, float y) override;
	void translate(hctm::Point2f increment) override;
	void rotate(const hctm::Point2f& pvt, float angleInDegree);
	void scale(float factor) override;
	float area() const override;
	void draw() override;
};

// MUTATORS
inline
void BulletSprite::setPostion(hctm::Point2f pos)
{
	auto old = d_pos;
	d_pos = pos;
	auto incr = d_pos - old;
	d_bullet.translate(incr);
}

inline
void BulletSprite::setColor(unsigned int r, unsigned int g, unsigned int b)
{
	d_bullet.setColor(r,g,b);
}

} // end namespace mygame
