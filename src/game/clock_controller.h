// colock_controller.h
#pragma 
#include "../engine/gameplay/acontroller.h"
#include "clock_sprite.h"
#include "../engine/gameplay/collidable_character.h"
#include "../engine/scene/scene.h"

namespace mygame
{

class ClockController : public hctg::AController
{
public:
	hctm::Point2f d_position;
	hctg::CollidableCharacter* cdCharacter;
	mygame::ClockSprite* clockSprite;

public:
	ClockController()
	{

	}

	~ClockController()
	{
		destory();
	}

	void create()
	{
		using namespace hctg;
		//d_position; // need to get a random point


		cdCharacter = new CollidableCharacter(d_position, 100.0f, 100.0f);
		clockSprite = new ClockSprite(d_position);

		addPawn(cdCharacter);
		addSprite(clockSprite);
		addCollider(cdCharacter);

		hcts::Scene::inst().addDrawable(d_sprite);
		//hcts::Scene::inst().addTickable(d_pawn);
		hcts::Scene::inst().addTickable(clockSprite);
		hcts::Scene::inst().addCollider(d_collider);

	}

	void preTick() override
	{
	}

	void tick() override
	{
		if (d_collider)
		{
			auto & set = hcts::Scene::inst().getSceneGraph().query(d_collider);
			// auto & set = hcts::Scene::inst().getSceneGraph().getAllColliders();
			for (auto & cd : set)
			{
				if (d_collider->doesCollide(cd->bounds()))
				{
					d_pawn->setVelocity(-d_pawn->velocity());
					d_pawn->tick(); // one tick back

					auto dir = d_collider->bounds().getCenter() 
						- cd->bounds().getCenter();
					// reverse dirction

					float speed = d_pawn->velocity().length();
					dir.normalize();
					dir *= speed;

					d_pawn->setVelocity(dir);

					d_sprite->scale(1.2f);
					clockSprite->setClockFaceColor(0, 255, 122); // debugging purpose
				}
			}
		}

		if (d_pawn && d_sprite)
		{
			d_pawn->tick();
			d_collider->bounds().translate(d_pawn->positionXY() - d_sprite->position());
			d_sprite->setPostion(d_pawn->positionXY());
		}
	}

	void destory()
	{
		//hcts::Scene::inst().removeDrawable(d_sprite);
		//hcts::Scene::inst().removeTickable(d_pawn);
		//hcts::Scene::inst().removeCollider(d_collider);

		removePawn();
		removeSprite();
		removeCollider();

		delete cdCharacter;
		delete clockSprite;
	}
};

} // end namespace mygame