// resource.h
#pragma once
#include "config_parser.h"

namespace hctd
{

#define INI_FILE_PATH "./config.ini"

enum ResValueName
{
	// frame rate
	FRAME_RATE = 0,
	// screen
	SCREEN_WIDTH,
	SCREEN_HEIGHT,
	// WALL
	WALL_THICKNESS,
	// CANNON
	CANNON_START_POS_X, // 
	CANNON_START_POS_Y, // screen_middle + 300 pixel

	CANNON_HEAD_START_POS_X,
	CANNON_HEAD_START_POS_Y,

	CANNON_MAX_ANGLE, // 180
	CANNON_MIN_ANGLE, // 0
	CANNON_DELTA_ROTATION, // delta angle
	// BULLET
	BULLET_LENGTH,
	BULLET_WIDTH,
	BULLET_SPEED,
	// CLOCK
	CLOCK_START_WIDTH,
	CLOCK_START_SPEED,
	CLOCK_MIN_WIDTH,
	// SUMMARY
	TOTAL_SIZE
};

class Resource
{
private:
	float d_data[TOTAL_SIZE];

	Resource();
	~Resource();
	// DELETED	
	Resource(const Resource &) = delete;
	Resource(Resource &&) = delete;
	Resource& operator=(const Resource &) = delete;
	Resource& operator=(Resource &&) = delete;
public:
	static Resource& inst();
	void createIni();
	void readInit(std::string path = INI_FILE_PATH);
	float getValue(ResValueName name);
};

} // end namepsace hctd
