// renderer.h
#pragma once
#include <vector>
#include "idrawable.h"

namespace hctr
{

class Renderer
{
private:
	std::vector<IDrawable*> d_drawables;
public:
	Renderer();
	~Renderer();
	void draw();
	void clearAll(unsigned int r, unsigned int g, unsigned int b);
	void addDrawable(IDrawable* drawable);
	void removeDrawable(IDrawable* drawable);
};

} // end namespace hctr