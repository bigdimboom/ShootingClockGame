// resource.cpp
#include "resource.h"
#include <assert.h>

namespace hctd
{

Resource::Resource()
{
	d_data[FRAME_RATE] = 50.0f;
	d_data[SCREEN_WIDTH] = 800.0f;
	d_data[SCREEN_HEIGHT] = 600.0f;

	d_data[WALL_THICKNESS] = 4.0f;

	d_data[CANNON_START_POS_X] = d_data[SCREEN_WIDTH] * 0.5f;
	d_data[CANNON_START_POS_Y] = d_data[SCREEN_HEIGHT] * 0.5f + 200.0f;
	d_data[CANNON_HEAD_START_POS_X] = d_data[CANNON_START_POS_X];
	d_data[CANNON_HEAD_START_POS_Y] = d_data[CANNON_START_POS_Y] - 35.0f;
	d_data[CANNON_MAX_ANGLE] = 180.0f;
	d_data[CANNON_MIN_ANGLE] = 0.0f;
	d_data[CANNON_DELTA_ROTATION] = 1.5f;

	d_data[BULLET_LENGTH] = 5.0f;
	d_data[BULLET_WIDTH] = 5.0f;
	d_data[BULLET_SPEED] = 5.0f;

	d_data[CLOCK_START_WIDTH] = 100.0f;
	d_data[CLOCK_START_SPEED] = 5.0f;
	d_data[CLOCK_MIN_WIDTH] = 100.0f;
}


Resource::~Resource()
{
}

Resource& Resource::inst()
{
	static Resource inst;
	return inst;
}

void Resource::readInit(std::string path)
{

}

float Resource::getValue(ResValueName name)
{
	assert(name >= 0 && name <= CLOCK_MIN_WIDTH);
	return d_data[name];
}

void Resource::createIni()
{

}

} // end namepsace hctd