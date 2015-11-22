// scene_graph.cpp
#include "scene_graph.h"
#include <assert.h>

namespace hcts
{

// HELPERS
void SceneGraph::_insertCollider(hctc::ICollider *collider,
								 std::vector<hctc::ICollider* >* table)
{
#ifdef _DEBUG
	assert(collider && table);
#endif
	hctm::Point2f top = collider->bounds().topLeftPoint();
	hctm::Point2f down = collider->bounds().downRightPoint();
	int topX, topY, downX, downY;
	topX = _preHash(top.x());
	topY = _preHash(top.y());
	downX = _preHash(down.x());
	downY = _preHash(down.y());

	topX = topX >= 0 ? topX : 0;
	topY = topY >= 0 ? topY : 0;
	downX = downX <= d_xSize ? downX : d_xSize;
	downY = downY <= d_ySize ? downY : d_ySize;


	for (int y = topY; y <= downY; ++y)
	{
		for (int x = topX; x <= downX; ++x)
		{
			table[y * d_xSize + x].push_back(collider);
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
	delete[] d_table;
	delete[] d_staticTable;
}

// ACCESSOR
const std::vector<hctc::ICollider* >& SceneGraph::getDynamicColliders() const
{
	return d_all;
}

const std::vector<hctc::ICollider* >& SceneGraph::getStaticColliders() const
{
	return d_staticAll;
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
		delete[] d_table;
	}

	if (d_staticTable != nullptr)
	{
		delete[] d_staticTable;
	}

	d_table = new std::vector<hctc::ICollider* >[(d_xSize + 1) * (d_ySize + 1)];
	d_staticTable = new std::vector<hctc::ICollider* >[(d_xSize + 1) * (d_ySize + 1)];

	// insert static colliders while building
	for (const auto & cder : d_staticAll)
	{
		_insertCollider(cder, d_staticTable);
	}
}

void SceneGraph::addCollider(hctc::ICollider *collider)
{
	assert(collider);

	if ((collider->flags() & DYNAMIC_COLLIDER) == DYNAMIC_COLLIDER)
	{
		d_all.push_back(collider);
	}
	else
	{
		d_staticAll.push_back(collider);
	}
}

void SceneGraph::removeCollider(hctc::ICollider *collider)
{
	assert(collider);
	if ((collider->flags() & DYNAMIC_COLLIDER) == DYNAMIC_COLLIDER)
	{
		for (auto i = d_all.begin(); i != d_all.end();)
		{
			if (*i == collider)
			{
				i = d_all.erase(i);
			}
			else
			{
				++i;
			}
		}
	}
	else
	{
		hctm::Point2f top = collider->bounds().topLeftPoint();
		hctm::Point2f down = collider->bounds().downRightPoint();
		int topX, topY, downX, downY;
		topX = _preHash(top.x());
		topY = _preHash(top.y());
		downX = _preHash(down.x());
		downY = _preHash(down.y());

		topX = topX >= 0 ? topX : 0;
		topY = topY >= 0 ? topY : 0;
		downX = downX <= d_xSize ? downX : d_xSize;
		downY = downY <= d_ySize ? downY : d_ySize;

		for (int y = topY; y <= downY; ++y)
		{
			for (int x = topX; x <= downX; ++x)
			{
				auto & c = d_staticTable[y * d_xSize + x];

				for (auto k = c.begin(); k != c.end();)
				{
					if (*k == collider)
					{
						k = c.erase(k);
					}
					else
					{
						++k;
					}
				}
			}
		}

		for (auto i = d_staticAll.begin(); i != d_staticAll.end();)
		{
			if (*i == collider)
			{
				i = d_staticAll.erase(i);
			}
			else
			{
				++i;
			}
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
	downX = _preHash(down.x());
	downY = _preHash(down.y());

	topX = topX >= 0 ? topX : 0;
	topY = topY >= 0 ? topY : 0;
	downX = downX <= d_xSize ? downX : d_xSize;
	downY = downY <= d_ySize ? downY : d_ySize;

	for (int y = topY; y <= downY; ++y)
	{
		for (int x = topX; x <= downX; ++x)
		{
			for (auto i : d_table[y * d_xSize + x])
			{
				d_qResult.insert(i);
			}
			for (auto j : d_staticTable[y * d_xSize + x])
			{
				d_qResult.insert(j);
			}
		}
	}

	return d_qResult;
}

void SceneGraph::preTick()
{
	// Nothing.
}

void SceneGraph::tick()
{
}

void SceneGraph::postTick()
{
	// insert static colliders
	for (int i = 0; i < d_xSize * d_ySize; ++i)
	{
		d_table[i].clear();
	}
	for (const auto & cder : d_all)
	{
		_insertCollider(cder, d_table);
	}
}

} // end namespace hcts