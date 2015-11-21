// collidable_character.cpp
#include "collidable_character.h"

namespace hctg
{

CollidableCharacter::CollidableCharacter(hctm::Point2f pos, float width, float height)
	: Character(pos)
	, d_bb(hctm::Point2f(pos.x() - width * 0.5f, pos.y() - height * 0.5f), width, height)
	, d_cdState(DYNAMIC_COLLIDER)
{
}


CollidableCharacter::~CollidableCharacter()
{
}

hctc::Aabb& CollidableCharacter::bounds()
{
	return d_bb;
}

unsigned short CollidableCharacter::flags() const
{
	return d_cdState;
}

void CollidableCharacter::setFlags(unsigned short flags)
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

bool CollidableCharacter::doesCollide(const hctc::Aabb & candidate)
{
	if (&d_bb == &candidate)
	{
		return false;
	}
	return d_bb.doesCollide(candidate);
}

} // end namespace hctg