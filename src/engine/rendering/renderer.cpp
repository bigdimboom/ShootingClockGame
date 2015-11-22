// renderer.cpp
#include "renderer.h"
#include <assert.h>
#include "../api/graphics.h"
#include <algorithm>

namespace hctr
{

// CONSTRUCTOR
Renderer::Renderer(int width, int height)
{

}

// DESTRUCTOR
Renderer::~Renderer()
{

}

// ACCESSOR
int Renderer::width() const
{
	return d_width;
}

int Renderer::height() const
{
	return d_height;
}

hctm::Point2f Renderer::positionTopLeft() const
{
	return d_topLeftStartingPoint;
}

// MUTATORS
void Renderer::setView(hctm::Point2f topLeft, int width, int height)
{
	d_topLeftStartingPoint = topLeft;
	d_width = width;
	d_height = height;
}

// MEMBER FUNCTIONS
void Renderer::draw()
{
	for (const auto & i : d_drawables)
	{
		i->draw();
	}
}

void Renderer::clearAll(unsigned int r, unsigned int g, unsigned int b)
{
	FillRect(0, 0, d_width, d_height, GetRGB(r,g,b));
}

void Renderer::addDrawable(IDrawable* drawable)
{
	assert(drawable);
	d_drawables.push_back(drawable);
}

void Renderer::removeDrawable(IDrawable* drawable)
{
	assert(drawable);
	auto i = d_drawables.begin();
	while (i != d_drawables.end())
	{
		if (*i == drawable)
		{
			i = d_drawables.erase(i);
		}
		else
		{
			++i;
		}
	}
}

bool Renderer::isActive() const
{
	return (d_width != 0 && d_height != 0);
}

} // end namespace hctr