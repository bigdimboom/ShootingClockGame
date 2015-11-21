// collidable_actor.h
#pragma once

#include "../scene/actor.h"
#include "../collision/icollider.h"

namespace hctg
{

class CollidableActor : public hcts::Actor, public hctc::ICollider
{
private:
	hctc::Aabb d_bb; // the bounding box
	unsigned short d_cdState;
public:
	CollidableActor(hctm::Point2f center, float width, float height);
	~CollidableActor();

	hctc::Aabb& bounds() override;
	unsigned short  flags() const override;
	void setFlags(unsigned short  flags) override;
	//bool canCollide(unsigned short flags) const override;
	bool doesCollide(const hctc::Aabb & candidate) override;
};

} // end namespace hctg