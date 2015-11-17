// acharacter.cpp
#include "acharacter.h"
#include <assert.h>

namespace hctg
{

// CONSTRUCTOR
ACharacter::ACharacter(AController* controller = nullptr)
{
}

// DESTRUCTOR
ACharacter::~ACharacter()
{
}


void ACharacter::addDrawable(hctr::IDrawable * drawable)
{
	assert(drawable);
	d_drawables.push_back(drawable);
}

void ACharacter::removeDrawable(hctr::IDrawable * drawable)
{
	assert(drawable);
	for (auto i = d_drawables.begin(); i != d_drawables.end(); ++i)
	{
		if (*i == drawable)
		{
			d_drawables.erase(i);
		}
	}
}

const std::vector<hctr::IDrawable*>& ACharacter::drawables() const
{
	return d_drawables;
}

} // end namespace hctg