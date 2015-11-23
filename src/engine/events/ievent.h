// ievent.h
#pragma once
#include <string>

namespace hcte
{

//typedef unsigned long EventType;
  // create a GUID to identify an event with a GUID generator.
  // e.g. {B1CEB228-AD05-4E8D-A477-6491843DE2ED}
  // syntax in c, DEFINE_GUID(<< name >> , 0xb1ceb228, 0xad05, 0x4e8d, 0xa4, 0x77, 0x64, 0x91, 0x84, 0x3d, 0xe2, 0xed);

enum  class EventType
{
	PLAYER_CMD
};

class IEvent
{
public:
	virtual ~IEvent(){}
	// virtual float timeStamp() const = 0;
	virtual const EventType & type() const = 0;
	  // return a GUID for fast comparision.
	virtual const std::string message() const = 0;
	  // return a human readable name for the event.
};

} // end namespace hcte

