// renderer.h
// this so called render is actrually "view"
#pragma once
#include <vector>
#include "idrawable.h"
#include "../math/point2f.h"

namespace hctr
{

class Renderer
{
private:
	std::vector<IDrawable*> d_drawables;
	int d_width;
	int d_height;
	hctm::Point2f d_topLeftStartingPoint;

	// DELETED
	Renderer(const Renderer &) = delete;
	Renderer(Renderer &&) = delete;
	Renderer& operator = (const Renderer &) = delete;
	Renderer& operator = (Renderer &&) = delete;

public:
	Renderer(int width = 0, int height = 0);
	~Renderer();

	// ACCESSOR
	int width() const;
	int height() const;
	hctm::Point2f positionTopLeft() const;

	// MUTATORS
	void setView(hctm::Point2f topLeft, int width, int height);

	// MEMBER FUNCTIONS
	void draw();
	void clearAll(unsigned int r, unsigned int g, unsigned int b);
	void addDrawable(IDrawable* drawable);
	void removeDrawable(IDrawable* drawable);
	bool isActive() const;
	  // is render width == 0 or height == 0;
};

} // end namespace hctr