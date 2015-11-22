#include "C_Application.h"
#include "engine\gameplay\collidable_pawn.h"

namespace hctg
{

static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, d_wallsN(hctm::Point2f(m_ScreenWidth * 0.5f, 0.0f), (float)m_ScreenWidth, 2.0f)
	, d_wallsW(hctm::Point2f(0.0f, m_ScreenHeight * 0.5f), 2.0f, (float)m_ScreenHeight)
	, d_wallsE(hctm::Point2f((float)m_ScreenWidth, m_ScreenHeight * 0.5f), 2.0f, (float)m_ScreenHeight)
	, d_wallsS(hctm::Point2f(m_ScreenWidth * 0.5f, (float)m_ScreenHeight), (float)m_ScreenWidth, 2.0f)
	, d_playerContrl(hctm::Point2f(m_ScreenWidth * 0.5f, m_ScreenHeight * 0.5f + 200.0f), 180.0f, 0.0f, 5.0f)
{
}


C_Application::~C_Application()
{
}

void C_Application::init()
{
	// TODO:: Read config file.
	d_render.setView(hctm::Point2f(0.0f, 0.0f), m_ScreenWidth, m_ScreenHeight);
	hcts::Scene::inst().setRenderer(&d_render);

	// Player
	d_playerContrl.addSprite
		(new mygame::CannonSprite(hctm::Point2f(m_ScreenWidth * 0.5f, m_ScreenHeight * 0.5f + 200.0f)));
	hcts::Scene::inst().addDrawable(d_playerContrl.sprite());
	hcts::Scene::inst().addTickable(&d_playerContrl);

	// Clock
	d_clockContol.addPawn(new CollidablePawn(
		hctm::Point2f(m_ScreenWidth * 0.5f, m_ScreenHeight * 0.5f), 100.0f, 100.f));
	d_clockContol.addCollider(dynamic_cast<hctc::ICollider*>(d_clockContol.pawn()));
	d_clockContol.addSprite(new mygame::ClockSprite(hctm::Point2f(m_ScreenWidth * 0.5f, m_ScreenHeight * 0.5f)));
	d_clockContol.pawn()->setVelocity(hctm::Point2f(0.8, 1.2));

	hcts::Scene::inst().addCollider(d_clockContol.collider());
	hcts::Scene::inst().addDrawable(d_clockContol.sprite());
	hcts::Scene::inst().addTickable(&d_clockContol);
	hcts::Scene::inst().addTickable(dynamic_cast<hcts::ITickable*>(d_clockContol.sprite()));

	// imaginary walls.
	hcts::Scene::inst().addCollider(&d_wallsE);
	hcts::Scene::inst().addCollider(&d_wallsW);
	hcts::Scene::inst().addCollider(&d_wallsS);
	hcts::Scene::inst().addCollider(&d_wallsN);

	// CD.
	hcts::Scene::inst().buildSceneGraph();
}

void C_Application::handleInput(T_PressedKey pressedKeys)
{
	//Key processing

	if (pressedKeys & s_KeyLeft)
	{
		hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD, "TURN_LEFT");
		hcte::EventBus::inst().enQueueEvent(ev);
	}
	if (pressedKeys & s_KeyRight)
	{
		hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD, "TURN_RIGHT");
		hcte::EventBus::inst().enQueueEvent(ev);
	}
	if (pressedKeys & s_KeySpace)
	{
		hcte::BasicEvent ev(hcte::EventType::PLAYER_CMD, "FIRE");
		hcte::EventBus::inst().enQueueEvent(ev);
	}
	if (pressedKeys & s_KeyUp)
	{
	}
	if (pressedKeys & s_KeyDown)
	{
	}
}

void C_Application::tick()
{
	hcts::Scene::inst().tick();
}

void C_Application::draw()
{
	hcts::Scene::inst().draw();
}

void C_Application::cleanUp()
{
	hcts::Scene::inst().removeCollider(&d_wallsE);
	hcts::Scene::inst().removeCollider(&d_wallsW);
	hcts::Scene::inst().removeCollider(&d_wallsS);
	hcts::Scene::inst().removeCollider(&d_wallsN);

	hcts::Scene::inst().removeCollider(d_clockContol.collider());
	hcts::Scene::inst().removeDrawable(d_clockContol.sprite());
	hcts::Scene::inst().removeTickable(&d_clockContol);
	hcts::Scene::inst().removeTickable(dynamic_cast<hcts::ITickable*>(d_clockContol.sprite()));

	delete d_clockContol.pawn();
	d_clockContol.removePawn();
	d_clockContol.removeCollider();

	delete d_clockContol.sprite();
	d_clockContol.removeSprite();

	hcts::Scene::inst().removeDrawable(d_playerContrl.sprite());
	delete d_playerContrl.sprite();
	d_playerContrl.removeSprite();
}

} // end namespace hctg
