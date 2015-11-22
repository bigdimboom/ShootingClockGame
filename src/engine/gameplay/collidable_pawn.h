// collidable_character.h
#pragma once
#include "../collision/icollider.h"
#include "../gameplay/pawn.h"

namespace hctg
{

class CollidablePawn : public Pawn, public hctc::ICollider
{
private:
	hctc::Aabb d_bb; // the bounding box
	unsigned short  d_cdState;
public:
	CollidablePawn(hctm::Point2f pos, float bindWidth, float bindHeight);
	virtual ~CollidablePawn();

	hctc::Aabb& bounds() override;
	unsigned short flags() const override;
	void setFlags(unsigned short  flags) override;
	//bool canCollide(unsigned short flags) const override;
	bool doesCollide(const hctc::Aabb & candidate) override;
};

} // end namespace hctg