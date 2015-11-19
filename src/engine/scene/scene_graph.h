#pragma once
#include "itickable.h"
#include "../collision/icollider.h"
#include "../collision/aabb.h"
#include <vector>

namespace hcts
{
class SceneGraph : public ITickable
{
private:
	std::vector<hctc::ICollider* > d_all;

	SceneGraph(const SceneGraph &) = delete;
	SceneGraph(SceneGraph &&) = delete;
	SceneGraph& operator = (const SceneGraph &) = delete;
	SceneGraph& operator = (SceneGraph &&) = delete;
public:
	SceneGraph();
	SceneGraph(hctm::Point2f topLeftCorner, float width, float height, 
			   int division, int maxDivision);
	~SceneGraph();

	// MEMBER FUNCTIONS
	void build(hctm::Point2f topLeftCorner, float width, float height,
			   int division, int maxDivision);
	void rebuild();
	void addCollider(hctc::ICollider *collider);
	void removeCollider(hctc::ICollider *collider);

	void query(const hctc::Aabb bounds);
	void query(const hctc::Aabb bounds, unsigned short flags);
	void query(hctm::Point2f topLeft, float width, float height);
	void query(hctm::Point2f topLeft, float width, float height, unsigned short flags);

	virtual void preTick() override;
	virtual void tick() override;
};
} // end namespace hcts