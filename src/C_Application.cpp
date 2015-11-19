#include "C_Application.h"

namespace hctg
{

static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, d_clock(hctm::Point2f(m_ScreenWidth / 2, m_ScreenHeight / 2))
	, d_cann(hctm::Point2f(m_ScreenWidth / 2, m_ScreenHeight / 2 + 100.0f))
{
	init();
}


C_Application::~C_Application()
{

}

void C_Application::init()
{
	// Read config file
	d_render.setView(hctm::Point2f(0.0f,0.0f), m_ScreenWidth, m_ScreenHeight);
	d_render.addDrawable(&d_clock);
	d_render.addDrawable(&d_cann);
	hcts::Scene::inst().setRenderer(&d_render);
	hcts::Scene::inst().addTickable(&d_clock);
}

void C_Application::handleInput(T_PressedKey pressedKeys)
{
	//Key processing

	if(pressedKeys & s_KeyLeft)
	{
	}

	if(pressedKeys & s_KeyRight)
	{
	}

	if(pressedKeys & s_KeyUp)
	{
	}

	if(pressedKeys & s_KeyDown)
	{

	}

	if(pressedKeys & s_KeySpace)
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
