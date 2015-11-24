// flock_controller.cpp
#include "flock_controller.h"
#include "actor_factory.h"
#include "sprite_factory.h"
#include "../engine/data/resource.h"

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
	ClockController* clockControl = new ClockController();
	ClockSprite* clockSprite = mygame::SpriteFactory::createClockSprite(pos, width);
	hctg::CollidablePawn* pawn = mygame::ActorFactory::createCDPawn(pos, width, width);
	clockControl->addPawn(pawn);
	clockControl->addCollider(pawn);
	clockControl->addSprite(clockSprite);
	clockControl->pawn()->setVelocity(vel);
	clockControl->collider()->setFlags(DYNAMIC_COLLIDER | CLOCK_COLLIDER);

	clockControl->addToPipeline();

	d_clocks.push_back(clockControl);
}

void FlockController::_destoryClock(ClockController* ptr)
{
	assert(ptr);

	ptr->removeFromPipeline();

	mygame::ActorFactory::destoryActor(ptr->pawn());
	mygame::SpriteFactory::destorySprite(ptr->sprite());
	ptr->removePawn();
	ptr->removeCollider();
	ptr->removeSprite();
}

// CONSTRUCTOR
FlockController::FlockController()
{
	srand((unsigned int)time(NULL));
}

// DESTRUCTOR
FlockController::~FlockController()
{
}

// MEMBERS
void FlockController::init()
{
	addToPipeline();
}

void FlockController::preTick()
{
}

void FlockController::tick()
{
	if (d_clocks.size() == 0)
	{
		// genetate two clcoks.
		float speed = hctd::Resource::inst().getValue(hctd::CLOCK_START_SPEED);
		float width = hctd::Resource::inst().getValue(hctd::CLOCK_START_WIDTH);
		_createClock(_randomPos(hctm::Point2f(150.0f, 150.0f), width, width), _randomVel(speed), width);
		_createClock(_randomPos(hctm::Point2f(300.0f, 300.0f), width, width), _randomVel(speed), width);
	}
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

			if ((*i)->collider()->bounds().width() <= hctd::Resource::inst().getValue(hctd::CLOCK_MIN_WIDTH))
			{
				_destoryClock(*i);
				delete *i;
				i = d_clocks.erase(i);
			}
			else
			{
				(*i)->sprite()->scale(0.8f);
				(*i)->collider()->bounds().scale(0.8f);
				(*i)->collider()->setFlags((*i)->collider()->flags() - HIT_BY_BULLET);
			}

		}
		else
		{
			++i;
		}
	}
}

void FlockController::cleanUp()
{
	for (auto i = d_clocks.begin(); i != d_clocks.end(); ++i)
	{
		_destoryClock(*i);
		delete *i;
	}
	removeFromPipeline();
}

void FlockController::addToPipeline()
{
	hcts::Scene::inst().addTickable(this);
}

void FlockController::removeFromPipeline()
{
	hcts::Scene::inst().removeTickable(this);
}

} // end namespace mygame