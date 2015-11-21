// collidable_character.h
#pragma once
#include "../collision/icollider.h"
#include "../gameplay/character.h"

namespace hctg
{

class CollidableCharacter : public Character,  public hctc::ICollider
{
private:
	hctc::Aabb d_bb; // the bounding box
	hctc::ColliderType d_cdState;
public:
	CollidableCharacter(hctm::Point2f pos, float bindWidth, float bindHeight);
	virtual ~CollidableCharacter();

	hctc::Aabb& bounds() override;
	hctc::ColliderType flags() const override;
	void setFlags(hctc::ColliderType flags) override;
	//bool canCollide(unsigned short flags) const override;
	bool doesCollide(const hctc::Aabb & candidate) override;
};

} // end namespace hctg