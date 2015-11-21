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
	hctc::ColliderType d_cdState;
public:
	CollidableActor(hctm::Point2f center, float width, float height);
	~CollidableActor();

	hctc::Aabb& bounds() override;
	hctc::ColliderType flags() const override;
	void setFlags(hctc::ColliderType flags) override;
	//bool canCollide(unsigned short flags) const override;
	bool doesCollide(const hctc::Aabb & candidate) override;
};

} // end namespace hctg