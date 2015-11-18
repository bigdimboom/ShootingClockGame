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

	// MEMBER FUNCTIONS
	virtual void translate(float x, float y) override;
	virtual void translate(hctm::Point2f increment) override;
	virtual void rotate(const hctm::Point2f& pvt, float angleInDegree);
	virtual void scale(float factor) override;
	virtual float area() const override;
	virtual void draw() override;
};

} // end namespace mygame
