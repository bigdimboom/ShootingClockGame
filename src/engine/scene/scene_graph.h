// scene_graph.h
// it uses spatial hashing for simplicity
#pragma once
#include "itickable.h"
#include "../collision/icollider.h"
#include "../collision/aabb.h"
#include <vector>
#include <list>
#include <set>

namespace hcts
{
class SceneGraph : public ITickable
{
private:
	float d_cellSizeFactor; // 1 / cellSize : faster
	int d_xSize;
	int d_ySize;

	std::list<hctc::ICollider* > d_all; // dynamic
	std::list<hctc::ICollider* > d_staticAll; // the statics

	std::vector<hctc::ICollider* >* d_table;
	std::vector<hctc::ICollider* >* d_staticTable;

	std::set<hctc::ICollider*> d_qResult;

	// HELPERS
	int _preHash(float pt1D);
	int _hash(const hctm::Point2f & point);

	void _insertCollider(hctc::ICollider *collider,
						 std::vector<hctc::ICollider* >* table);

	SceneGraph(const SceneGraph &) = delete;
	SceneGraph(SceneGraph &&) = delete;
	SceneGraph& operator = (const SceneGraph &) = delete;
	SceneGraph& operator = (SceneGraph &&) = delete;
public:
	SceneGraph();
	SceneGraph(float width, float height, float cellSize);
	~SceneGraph();

	// ACCESSOR
	const std::list<hctc::ICollider* >& getStaticColliders() const;
	const std::list<hctc::ICollider* >& getDynamicColliders() const;

	// MEMBER FUNCTIONS
	void build(float width, float height, float cellSize);

	void rebuild();

	void addCollider(hctc::ICollider *collider);
	void removeCollider(hctc::ICollider *collider);

	const std::set<hctc::ICollider*>& query(hctc::ICollider *collider);

	virtual void preTick() override;
	virtual void tick() override;
	virtual void postTick() override;
};

// HELPERS
inline
int SceneGraph::_preHash(float pt1D)
{
	return (int)floor(pt1D * d_cellSizeFactor);
}

inline
int SceneGraph::_hash(const hctm::Point2f & point)
{
	return _preHash(point.x()) + _preHash(point.y()) * d_xSize;
}

} // end namespace hcts