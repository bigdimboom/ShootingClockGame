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
	, d_top((float)m_CannonX, (float)m_CannonY)
	, d_left((float)m_CannonX - 10.0f, (float)m_CannonY + 30.0f)
	, d_right((float)m_CannonX + 10.0f, (float)m_CannonY + 30.0f)
	, d_pvt((float)m_CannonX, (float)m_CannonY + 30.0f)
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

}

} // end namespace hctg
