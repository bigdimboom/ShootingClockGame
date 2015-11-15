// event_dispatcher.cpp
#include "event_dispatcher.h"
#include <algorithm>

namespace hcte
{

// CONSTRUCTORS
EventDispatcher::EventDispatcher()
{
}

// DESTRUCTOR
EventDispatcher::~EventDispatcher()
{
}

// MEMBER FUNCTIONS
void EventDispatcher::dispatch(const IEvent & ev)
{
	std::string evName = ev.name();
	auto got = d_listeners.find(evName);
	if (got != d_listeners.end())
	{
		for (auto callBacks : got->second )
		{
			if (callBacks && *callBacks)
			{
				(*callBacks)(ev);
			}
		}
	}
}

void EventDispatcher::add(const std::string& eventName,
						  EventListenerCallbacksPtr listener)
{
	assert(listener);
	d_listeners[eventName].push_back(listener);
}

void EventDispatcher::remove(const std::string& eventName, 
							 EventListenerCallbacksPtr listener)
{
	assert(listener);
	auto got = d_listeners.find(eventName);

	if (got != d_listeners.end())
	{
		auto vecPtr = &(got->second);
		vecPtr->erase(std::remove(vecPtr->begin(), vecPtr->end(), listener), vecPtr->end());
	}
}

void EventDispatcher::preTick()
{
}

void EventDispatcher::tick()
{
}

#ifdef UNIT_TEST

void unitTest() // test for control and sprite interaction
{
}
#endif

} // end namespace sgde

