#ifndef TEST_C_APPLICATION_H
#define TEST_C_APPLICATION_H

#include "engine\math\point2f.h"

using namespace hctm;

class C_Application
{
public:
	
	typedef unsigned int T_PressedKey;

	C_Application(int screenWidth, int screenHeight);
	~C_Application();

	/// Tick is called on fix framerate (50fps)
	void init();
	void tick(T_PressedKey pressedKeys);
	void draw();

	static const T_PressedKey s_KeyLeft  = 0x01;
	static const T_PressedKey s_KeyUp    = 0x02;
	static const T_PressedKey s_KeyRight = 0x04;
	static const T_PressedKey s_KeyDown  = 0x08;
	static const T_PressedKey s_KeySpace = 0x10;

private:

	const int	m_ScreenWidth;
	const int	m_ScreenHeight;
	
	// Members for sample tick
	int			m_CannonX;
	int			m_CannonY;

	
	
	Point2f d_top;
	Point2f d_left;
	Point2f d_right;
	Point2f d_pvt;

};

#endif // #ifndef TEST_C_APPLICATION_H
