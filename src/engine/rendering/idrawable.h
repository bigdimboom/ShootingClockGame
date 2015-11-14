// idrawable.h
#pragma once

namespace hctr // hangar coding test render
{

class IDrawable
{
public:
	virtual ~IDrawable(){}
	virtual void draw() = 0;
};

}
