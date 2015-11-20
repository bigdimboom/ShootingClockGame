// scene_graph.cpp
#include "scene_graph.h"
#include <assert.h>

namespace hcts
{

// HELPERS
void SceneGraph::_insertCollider(hctc::ICollider *collider)
{
	hctm::Point2f top = collider->bounds().topLeftPoint();
	hctm::Point2f down = collider->bounds().downRightPoint();
	int topX, topY, downX, downY;
	topX = _preHash(top.x());
	topY = _preHash(top.y());
	downX = _preHash(top.x());
	downY = _preHash(top.y());

	for (int y = topY; y < downY + 1; ++y)
	{
		for (int x = topX; x < downX + 1; ++x)
		{
			d_table[y * d_xSize + x].push_back(collider);
		}
	}
}

SceneGraph::SceneGraph()
{
}

SceneGraph::SceneGraph(float width, float height, float cellSize)
	: d_table(nullptr)
	, d_cellSizeFactor(1.0f / cellSize)
	, d_xSize((int)floor(width * d_cellSizeFactor))
	, d_ySize((int)floor(height * d_cellSizeFactor))
{
}

SceneGraph::~SceneGraph()
{
	delete d_table;
}

// ACCESSOR
const std::vector<hctc::ICollider* >& SceneGraph::getAllColliders() const
{
	return d_all;
}

void SceneGraph::build(float width, float height, float cellSize)
{
	d_cellSizeFactor = 1.0f / cellSize;
	d_xSize = (int)floor(width * d_cellSizeFactor);
	d_ySize = (int)floor(height * d_cellSizeFactor);
	rebuild();
}

void SceneGraph::rebuild()
{
	if (d_table != nullptr)
	{
		delete d_table;
	}
	d_table = new std::vector<hctc::ICollider* >[d_xSize * d_ySize];
}

void SceneGraph::addCollider(hctc::ICollider *collider)
{
	assert(collider);
	d_all.push_back(collider);
}

void SceneGraph::removeCollider(hctc::ICollider *collider)
{
	assert(collider);
	auto i = d_all.begin();
	for (; i != d_all.end();)
	{
		if (*i == collider)
		{
			d_all.erase(i);
		}
		else
		{
			++i;
		}
	}
}

const std::set<hctc::ICollider*> & SceneGraph::query(hctc::ICollider *collider)
{
	assert(collider);

	d_qResult.clear();

	hctm::Point2f top = collider->bounds().topLeftPoint();
	hctm::Point2f down = collider->bounds().downRightPoint();
	int topX, topY, downX, downY;
	topX = _preHash(top.x());
	topY = _preHash(top.y());
	downX = _preHash(top.x());
	downY = _preHash(top.y());

	for (int y = topY; y < downY + 1; ++y)
	{
		for (int x = topX; x < downX + 1; ++x)
		{
			for (const auto & i : d_table[x + d_xSize * y])
			{
				d_qResult.insert(i);
			}
		}
	}

	return d_qResult;
}

void SceneGraph::preTick()
{
	// Nothing
}

void SceneGraph::tick()
{
	for (int i = 0; i < d_xSize * d_ySize; ++i)
	{
		d_table[i].clear();
	}

	for (const auto & cder : d_all)
	{
		_insertCollider(cder);
	}
}

} // end namespace hcts