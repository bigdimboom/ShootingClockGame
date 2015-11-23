// flock_controller.cpp
#include "flock_controller.h"
#include <assert.h>
#include <time.h>

namespace mygame
{

// HELPES
hctm::Point2f FlockController::_randomPos(hctm::Point2f start, float width, float height)
{
	hctm::Point2f ret;
	int x = rand() % (int)width;
	int y = rand() % (int)height;
	ret.setX(start.x() + (float)x);
	ret.setY(start.y() + (float)y);
	return ret;
}

hctm::Point2f FlockController::_randomVel(float speed)
{
	int x = rand() % (int)10;
	int y = rand() % (int)10;
	hctm::Point2f ret((float)x, (float)y);
	ret.normalize();
	ret *= speed;
	return ret;
}

void FlockController::_createClock(hctm::Point2f pos, hctm::Point2f vel, float width)
{
	d_clocks.push_back(new ClockController);
	int i = d_clocks.size() - 1;
	d_clocks[i]->addPawn(new hctg::CollidablePawn(pos, width, width));
	d_clocks[i]->addCollider(dynamic_cast<hctc::ICollider*>(d_clocks[i]->pawn()));
	d_clocks[i]->addSprite(new mygame::ClockSprite(pos, width, width));
	d_clocks[i]->pawn()->setVelocity(vel);
	d_clocks[i]->collider()->setFlags(DYNAMIC_COLLIDER | CLOCK_COLLIDER);

	hcts::Scene::inst().addCollider(d_clocks[i]->collider());
	hcts::Scene::inst().addDrawable(d_clocks[i]->sprite());
	hcts::Scene::inst().addTickable(d_clocks[i]);
	hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(d_clocks[i]->sprite()));
}

void FlockController::_destoryClock(ClockController* ptr)
{
	assert(ptr);

	hcts::Scene::inst().removeTickable(ptr);
	hcts::Scene::inst().removeCollider(ptr->collider());
	hcts::Scene::inst().removeDrawable(ptr->sprite());
	hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(ptr->sprite()));

	delete ptr->pawn();
	ptr->removePawn();
	ptr->removeCollider();
	delete ptr->sprite();
	ptr->removeSprite();
}

// CONSTRUCTOR
FlockController::FlockController()
{
}

// DESTRUCTOR
FlockController::~FlockController()
{
}

// MEMBERS
void FlockController::init()
{
	//srand((unsigned int)time(NULL));
	hcts::Scene::inst().addTickable(this);
	_createClock(_randomPos(hctm::Point2f(200.0f, 300.0f), 100, 100), _randomVel(2.0f), 100.0f);
	_createClock(_randomPos(hctm::Point2f(150.0f, 150.0f), 250, 250), _randomVel(2.0f), 100.0f);
}

void FlockController::preTick()
{

}

void FlockController::tick()
{
}

void FlockController::postTick()
{

	// TODO:
	// collsion check
	// check if HIT_BY_BULLET

	for (auto i = d_clocks.begin(); i != d_clocks.end();)
	{
		if (((*i)->collider()->flags() & HIT_BY_BULLET) == HIT_BY_BULLET) // the bullet is hit something
		{
			// DO SOMETHING to the current clock.
			//(*i)->sprite()->scale(0.8f);
			//(*i)->collider()->bounds().scale(0.8f);
			//(*i)->collider()->setFlags((*i)->collider()->flags() - HIT_BY_BULLET);
			//++i;

			_destoryClock(*i);
			delete *i;
			i = d_clocks.erase(i);

		}
		else
		{
			++i;
		}
	}

	if (d_clocks.size() == 0)
	{
		// genetate two clcoks.
		_createClock(_randomPos(hctm::Point2f(200.0f, 300.0f), 150, 150), _randomVel(2.0f), 100.0f);
		_createClock(_randomPos(hctm::Point2f(150.0f, 150.0f), 150, 150), _randomVel(2.0f), 100.0f);
	}
}

void FlockController::cleanUp()
{
	for (auto i = d_clocks.begin(); i != d_clocks.end(); ++i)
	{
		_destoryClock(*i);
	}
}

} // end namespace mygame