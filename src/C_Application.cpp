#include "C_Application.h"
#include "engine/api/graphics.h"
#include "engine/api/time.h"

namespace hctg
{

static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_CannonX(m_ScreenWidth / 2)
	, m_CannonY(m_ScreenHeight / 2)
	, d_rec(Point2f(100.0f,100.f), 30.0f, 30.0f, 255, 0, 0)
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

void C_Application::handleInput(T_PressedKey key)
{

}

void C_Application::tick()
{

}

void C_Application::draw()
{
	FillRect(0, 0, m_ScreenWidth, m_ScreenHeight,0);
}

} // end namespace hctg
