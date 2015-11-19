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
	void translate(float x, float y) override;
	void translate(hctm::Point2f increment) override;
	void rotate(const hctm::Point2f& pvt, float angleInDegree);
	void scale(float factor) override;
	float area() const override;
	void draw() override;
};

} // end namespace mygame
