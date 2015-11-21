#include "C_Application.h"

namespace hctg
{

static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
{
}


C_Application::~C_Application()
{

}

void C_Application::init()
{
	// TODO:: Read config file
	d_render.setView(hctm::Point2f(0.0f, 0.0f), m_ScreenWidth, m_ScreenHeight);
	hcts::Scene::inst().setRenderer(&d_render);
	hcts::Scene::inst().buildSceneGraph();

	d_clcokCtrl.d_position = hctm::Point2f(m_ScreenWidth *0.5f, m_ScreenHeight * 0.5f);
	d_clcokCtrl.create();
	d_clcokCtrl.pawn()->setVelocity(hctm::Point2f(0.0f, 1.0f));
	hcts::Scene::inst().addTickable(&d_clcokCtrl);

	d_clcokCtrlw.d_position = hctm::Point2f(m_ScreenWidth *0.5f, (float)m_ScreenHeight);
	d_clcokCtrlw.create();
	d_clcokCtrlw.pawn()->setVelocity(hctm::Point2f(0.0f, -1.0f));
	hcts::Scene::inst().addTickable(&d_clcokCtrlw);


	d_clcokCtrlr.d_position = hctm::Point2f(0.0 + 100.0f, m_ScreenHeight * 0.5f);
	d_clcokCtrlr.create();
	d_clcokCtrlr.pawn()->setVelocity(hctm::Point2f(1.0f, 0.0f));
	hcts::Scene::inst().addTickable(&d_clcokCtrlr);


	d_playerContrl.init(hctm::Point2f(m_ScreenWidth * 0.5f, m_ScreenHeight * 0.5f + 200.0f), 180.0f, 0, 2.0f);
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

} // end namespace hctg
