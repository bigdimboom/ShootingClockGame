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
	, d_rec(Point2f(100.0f,100.f), 30.0f, 30.0f)
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
	if (key  & s_KeyUp)
	{
		d_rec.rotate(Point2f(d_rec.d_downLeft), -10);
		
	}

	if (key  & s_KeyDown)
	{
		d_rec.rotate(Point2f(d_rec.d_downLeft), 10);
	}

	if (key  & s_KeySpace)
	{
		d_rec.scale(1.5);
	}
}

void C_Application::tick()
{

}

void C_Application::draw()
{
	FillRect(0, 0, m_ScreenWidth, m_ScreenHeight, 0);

	DrawLine(d_rec.d_topLeft.x(), d_rec.d_topLeft.y(), d_rec.d_topRight.x(), d_rec.d_topRight.y(), GetRGB(255, 0, 0));
	DrawLine(d_rec.d_downLeft.x(), d_rec.d_downLeft.y(), d_rec.d_downRight.x(), d_rec.d_downRight.y(), GetRGB(255, 0, 0));
	DrawLine(d_rec.d_topLeft.x(), d_rec.d_topLeft.y(), d_rec.d_downLeft.x(), d_rec.d_downLeft.y(), GetRGB(255, 0, 0));
	DrawLine(d_rec.d_topRight.x(), d_rec.d_topRight.y(), d_rec.d_downRight.x(), d_rec.d_downRight.y(), GetRGB(255, 0, 0));
}

} // end namespace hctg
