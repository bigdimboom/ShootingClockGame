#include "C_Application.h"
#include "engine/api/graphics.h"
#include "engine/api/time.h"


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
}


C_Application::~C_Application()
{

}


void C_Application::tick(T_PressedKey pressedKeys)
{
	// Sample tick

	// Clear screen on cannon position

	// FillRect(m_CannonX-10, m_CannonY, 21, 31, GetRGB(0, 0, 0));

	FillRect(0, 0, m_ScreenWidth, m_ScreenHeight, 0);

	// Key processing

	//if(pressedKeys & s_KeyLeft)
	//{
	//	m_CannonX = max(0, m_CannonX-4);
	//}

	//if(pressedKeys & s_KeyRight)
	//{
	//	m_CannonX = min(m_ScreenWidth, m_CannonX+4);
	//}

	//if(pressedKeys & s_KeyUp)
	//{
	//	m_CannonY = max(0, m_CannonY-4);
	//}

	//if(pressedKeys & s_KeyDown)
	//{
	//	m_CannonY = min(m_ScreenHeight, m_CannonY+4);
	//}

	//if(pressedKeys & s_KeySpace)
	//{
	//}

	if(pressedKeys & s_KeyLeft)
	{
		d_top.rotate(d_pvt,-5);
		d_left.rotate(d_pvt, -5);
		d_right.rotate(d_pvt, -5);
	}

	if(pressedKeys & s_KeyRight)
	{
		d_top.rotate(d_pvt, 5);
		d_left.rotate(d_pvt, 5);
		d_right.rotate(d_pvt, 5);
	}

	// Draw cannon

	DrawLine(d_top.x(),  d_top.y(),    d_left.x(),  d_left.y(),  GetRGB(255,   0,   0));
	DrawLine(d_top.x(),  d_top.y(),    d_right.x(),  d_right.y(),  GetRGB(0, 255, 0)    );
	DrawLine(d_left.x(), d_left.y(),   d_right.x(), d_right.y(), GetRGB(  0,   0, 255));
}
