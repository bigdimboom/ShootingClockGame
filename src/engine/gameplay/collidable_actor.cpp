// collidable_actor.cpp
#include "collidable_actor.h"

namespace hctg
{

CollidableActor::CollidableActor(hctm::Point2f pos, float width, float height)
	: Actor(pos)
	, d_bb(hctm::Point2f(pos.x() - width * 0.5f, pos.y() - height *0.5f), width, height)
	, d_cdState(hctc::ColliderType::STATIC_COLLIDER)
{
}


CollidableActor::~CollidableActor()
{
}

hctc::Aabb& CollidableActor::bounds()
{
	return d_bb;
}

hctc::ColliderType CollidableActor::flags() const
{
	return d_cdState;
}

void CollidableActor::setFlags(hctc::ColliderType flags)
{
#ifdef _DEBUG
	std::cerr << "No set happened.\n";
#endif
}

bool CollidableActor::doesCollide(const hctc::Aabb & candidate)
{
	if (&d_bb == &candidate)
	{
		return false;
	}
	return d_bb.doesCollide(candidate);
}

} // end namespace hctg