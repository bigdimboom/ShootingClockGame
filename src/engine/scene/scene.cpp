// scene.cpp
#include "scene.h"
#include <assert.h>
#include "../events/event_bus.h"

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

hcts::SceneGraph& Scene::getSceneGraph()
{
	return d_sceneGraph;
}

// MEMBER FUNCTIONS
void Scene::tick()
{
	for (auto i = d_tickables.begin(); i != d_tickables.end(); ++i)
	{
		(*i)->preTick(); // precess inputs , rarely used
	}

	for (auto i = d_tickables.begin(); i != d_tickables.end(); ++i)
	{
		(*i)->tick(); // update game states
	}

	for (auto i = d_tickables.begin(); i != d_tickables.end(); ++i)
	{
		(*i)->postTick(); // process game states
	}

	d_sceneGraph.postTick();  // reload scene_graph
	hcte::EventBus::inst().postTick(); // process events or it could add to preTick()

	// Sync
	for (auto i = d_tickables.begin(); i != d_tickables.end();)
	{
		if (*i == &NullTickable::inst())
		{ 
			i = d_tickables.erase(i);
		}
		else
		{
			++i;
		}
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
	for (auto i = d_tickables.begin(); i != d_tickables.end();++i)
	{
		if (*i == tickable)
		{
			(*i) = &NullTickable::inst();
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

void Scene::addDrawable(hctr::IDrawable* drawable)
{
	if (d_renderer)
	{
		assert(drawable);
		d_renderer->addDrawable(drawable);
	}
}

void Scene::removeDrawable(hctr::IDrawable* drawable)
{
	if (d_renderer)
	{
		assert(drawable);
		d_renderer->removeDrawable(drawable);
	}
}

void Scene::buildSceneGraph(float cellSize)
{
	if (d_renderer)
	{
		d_sceneGraph.build((float)d_renderer->width(), 
						   (float)d_renderer->height(), 
						   cellSize);
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