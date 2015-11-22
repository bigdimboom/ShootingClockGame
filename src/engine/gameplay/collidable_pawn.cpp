// collidable_character.cpp
#include "collidable_pawn.h"

namespace hctg
{

CollidablePawn::CollidablePawn(hctm::Point2f pos, float width, float height)
	: Pawn(pos)
	, d_bb(hctm::Point2f(pos.x() - width * 0.5f, pos.y() - height * 0.5f), width, height)
	, d_cdState(DYNAMIC_COLLIDER)
{
}


CollidablePawn::~CollidablePawn()
{
}

hctc::Aabb& CollidablePawn::bounds()
{
	return d_bb;
}

unsigned short CollidablePawn::flags() const
{
	return d_cdState;
}

void CollidablePawn::setFlags(unsigned short flags)
{
	d_cdState = flags;
}

//bool CollidableCharacter::canCollide(unsigned short flags) const
//{
//	// TODO: 
//	//
//	//
//	//
//	return false;
//}

bool CollidablePawn::doesCollide(const hctc::Aabb & candidate)
{
	if (&d_bb == &candidate)
	{
		return false;
	}
	return d_bb.doesCollide(candidate);
}

} // end namespace hctg