// scene.h
// a singlton: scene manager, wrapping scene-graph, tickables and render
// contains a render, a scene-graph for collision
// it can add actors.
#pragma once
#include <vector>
#include "../scene/itickable.h"
#include "../collision/icollider.h"
#include "../rendering/renderer.h"
#include "scene_graph.h"

namespace hcts
{

class Scene
{
private:

	std::vector<ITickable*> d_tickables;
	  // for tickable iterations.
	hcts::SceneGraph d_sceneGraph;

	hctr::Renderer* d_renderer;

	// CONSTRUCTORS
	Scene();
	  // default constructor.
	Scene(const Scene &) = delete;
	  // copy constructor.
	Scene(Scene &&) = delete;
	  // move constructor.

	~Scene();

	// OPERATOR OVERLOADS
	Scene& operator =(const Scene &) = delete;
	  // copy assignment.
	Scene& operator =(Scene &&) = delete;
	  // move assignment.
public:
	// ACCESSORS
	static Scene& inst();
	  // the access point of a singleton class.

	// ACCESSORS
	const hcts::SceneGraph& sceneGraph() const;

	// MEMBER FUNCTIONS
	void tick();
	  // place it in main loop
	void draw();
	  // aka update
	void addTickable(ITickable* tickable);
	  // add tickable aka scene components.
	void removeTickable(ITickable* tickable);
	  // remove tickable aka scene components.
	  // use object manager to alloc/dealloc memory(outside of this class).

	void addCollider(hctc::ICollider* collider);
	void removeCollider(hctc::ICollider* collider);

	void buildSceneGraph(float cellSize = 50.0f); // min clock size: 5 by 5 max: 100 by 100

	void setRenderer(hctr::Renderer* renderer);
	  // allocate renderer on stack, 
	  // we are going to have the renderer be part of the scene 
	  //as it will be needed by other elements.
};

} // end namespace hcts