#include "C_Application.h"
#include "engine/api/graphics.h"
#include "engine/api/time.h"
#include "engine\events\event_bus.h"

namespace hctg
{

static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_CannonX(m_ScreenWidth / 2)
	, m_CannonY(m_ScreenHeight / 2)
	, d_rec1(Point2f(100.0f, 100.f), 20.0f, 20.0f, 255, 255, 255)
	, d_rec2(Point2f(200.0f, 200.f), 20.0f, 20.0f, 255, 0, 0)
	, d_cd1(Point2f(100.0f, 100.f), 20.0f, 20.0f)
	, d_cd2(Point2f(200.0f, 200.f), 20.0f, 20.0f)
{
	init();
}


C_Application::~C_Application()
{

}

void C_Application::init()
{
	// Read config file
}

void C_Application::handleInput(T_PressedKey pressedKeys)
{
	//Key processing

	if(pressedKeys & s_KeyLeft)
	{
		d_rec1.translate(-10, 0);
		d_cd1.translate(-10, 0);
	}

	if(pressedKeys & s_KeyRight)
	{
		d_rec1.translate(10, 0);
		d_cd1.translate(10, 0);
	}

	if(pressedKeys & s_KeyUp)
	{
		d_rec1.translate(0, -10);
		d_cd1.translate(0, -10);
	}

	if(pressedKeys & s_KeyDown)
	{
		d_rec1.translate(0, 10);
		d_cd1.translate(0, 10);
	}

	if(pressedKeys & s_KeySpace)
	{
		d_rec1.setColor(rand() % 255, rand() % 255, rand() % 255);
	}
}

void C_Application::tick()
{
}

void C_Application::draw()
{
	FillRect(0, 0, m_ScreenWidth, m_ScreenHeight,0);

	if (!d_cd1.doesCollide(d_cd2))
	{
		d_rec1.draw();
		d_rec2.draw();
	}
	else
	{
		d_rec2.draw();
	}

}

} // end namespace hctg
