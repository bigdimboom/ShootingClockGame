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
	EventType type = ev.type();
	auto got = d_listeners.find(type);
	if (got != d_listeners.end())
	{
		for (const auto & func : got->second)
		{
			if (func && *func)
			{
				(*func)(ev);
			}
		}
	}
}

void EventDispatcher::add(const IEvent & ev, EventListenerCallbacksPtr listener)
{
	assert(listener);
	d_listeners[ev.type()].push_back(listener);
}

void EventDispatcher::remove(const IEvent & ev, EventListenerCallbacksPtr listener)
{
	assert(listener);
	auto got = d_listeners.find(ev.type());

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

