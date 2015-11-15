// renderer.cpp
#include "renderer.h"
#include <assert.h>

namespace hctr
{


void Renderer::addDrawable(IDrawable* drawable)
{
	assert(drawable);
	d_drawables.push_back(drawable);
}

void Renderer::removeDrawable(IDrawable* drawable)
{
	assert(drawable);
}

} // end namespace hctr