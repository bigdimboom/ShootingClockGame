// asprite.cpp
#include "asprite.h"

namespace hctg
{

// CONSTRUCTOR
ASprite::ASprite(hctm::Point2f pos)
	:d_pos(pos)
{
}

// DESTRUCTOR
ASprite::~ASprite()
{
}

//ACCESSOR
hctm::Point2f ASprite::position() const
{
	return d_pos;
}

//MUTATORS
void ASprite::setPostion(hctm::Point2f pos)
{
	d_pos = pos;
}

} // end namespace hctg