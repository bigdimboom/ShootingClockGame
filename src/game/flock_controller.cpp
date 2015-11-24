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
	int x = rand() % (int)width + 1;
	int y = rand() % (int)height + 1;
	ret.setX(start.x() + (float)x);
	ret.setY(start.y() + (float)y);
	return ret;
}

hctm::Point2f FlockController::_randomVel(float speed)
{
	int x = rand() % (int)10 + 1;
	int y = rand() % (int)10 + 1;
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
		_createClock(_randomPos(hctm::Point2f(width, width), width, width), _randomVel(-speed), width);
		_createClock(_randomPos(hctm::Point2f(hctd::Resource::inst().getValue(hctd::SCREEN_WIDTH) * 0.5f, 
											  hctd::Resource::inst().getValue(hctd::SCREEN_HEIGHT) * 0.5f), 
											  width, width), 
											  _randomVel(speed),
											  width);
	}
}

void FlockController::postTick()
{
	// TODO:
	// collsion check
	// check if HIT_BY_BULLET

	hctm::Point2f pos;
	hctm::Point2f vel;
	float width = 0.0f;
	static int count = 0;

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
				// child behavior
				pos = (*i)->pawn()->positionXY();
				vel = -((*i)->pawn()->velocity());
				vel.setY(vel.y() * 1.2f); // set new clock velocity

				width = (*i)->collider()->bounds().width(); 
				pos.setX(pos.x() - width * 0.5f); // set new clock position

				// father behavior
				auto tmpPosFather = (*i)->pawn()->positionXY();
				tmpPosFather.setX(tmpPosFather.x() + width * 0.5f);
				(*i)->pawn()->setPosition(tmpPosFather); // set Father clock position.

				(*i)->sprite()->scale(0.7f); // shrink father clock size
				(*i)->collider()->bounds().scale(0.6f);
				(*i)->collider()->setFlags((*i)->collider()->flags() - HIT_BY_BULLET);


				width *= 0.3f; // set new child clock width

				++i;
			}

		}
		else
		{
			++i;
		}
	}

	if (width && d_clocks.size() <= hctd::Resource::inst().getValue(hctd::CLOCK_MAX_NUM))
	{
		_createClock(pos, vel, width);
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