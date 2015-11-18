// scene.cpp
#include "scene.h"
#include <assert.h>

namespace hcts
{

// CONSTRUCTORS
Scene::Scene() : d_renderer(nullptr)
{
}

Scene::~Scene()
{
}

// ACCESSORS
Scene& Scene::inst()
{
	static Scene scene;
	return scene;
}

void Scene::tick()
{
	for (const auto & i : d_tickables)
	{
		i->preTick();
		d_sceneGraph.preTick();
	}

	for (const auto & i : d_tickables)
	{
		i->tick();
		d_sceneGraph.tick();
	}
}
void Scene::draw()
{
	if (d_renderer)
	{
		d_renderer->clearAll(0, 0, 0);
		d_renderer->draw();
	}
}

void Scene::addTickable(ITickable* tickable)
{
	assert(tickable);
	d_tickables.push_back(tickable);
}

void Scene::removeTickable(ITickable* tickable)
{
	assert(tickable);
	for (auto i = d_tickables.begin(); i != d_tickables.end(); ++i)
	{
		if (*i == tickable)
		{
			d_tickables.erase(i);
		}
	}
}

void Scene::addCollider(hctc::ICollider* collider)
{
	assert(collider);
	d_sceneGraph.addCollider(collider);
}

void Scene::removeCollider(hctc::ICollider* collider)
{
	assert(collider);
	d_sceneGraph.removeCollider(collider);
}

void Scene::buildSceneGraph(int division, int maxDivision)
{
	if (d_renderer)
	{
		d_sceneGraph.build(d_renderer->positionTopLeft(), d_renderer->width(), d_renderer->height(), division, maxDivision);
	}
	else
	{
		std::cerr << "warnning: renderer unset.\n";
	}
}

void Scene::setRenderer(hctr::Renderer* renderer)
{
	d_renderer = renderer;
}


} // end namespace hcts