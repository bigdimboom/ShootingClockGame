// event_dispatcher.h
#pragma once
#include <assert.h>
#include <functional>
#include "../scene/itickable.h"
#include "ievent.h"
#include <unordered_map>
#include <vector>

namespace  hcte
{

typedef std::function<void(const IEvent &)> EventListenerCallbacks;
typedef std::function<void(const IEvent &)>* EventListenerCallbacksPtr;
typedef std::vector<EventListenerCallbacksPtr> EventListenerList;


class EventDispatcher : public hcts::ITickable
{
private:
	std::unordered_map<EventType, EventListenerList> d_listeners;
	  // store a map of listeners ready for exec.
	  // listeners have to manage themslves.

	//DELETED
	EventDispatcher(const EventDispatcher &) = delete;
	EventDispatcher(EventDispatcher &&) = delete;
	EventDispatcher& operator=(const EventDispatcher &) = delete;
	EventDispatcher& operator=(EventDispatcher &&) = delete;

public:
	EventDispatcher();
	~EventDispatcher();

	// MEMBER FUNCTIONS
	void dispatch(const IEvent & ev);
	  // called as part of tick, synchronous.
	void add(const IEvent & ev, EventListenerCallbacksPtr listener);
	void remove(const IEvent & ev, EventListenerCallbacksPtr listener);

	void preTick() override;
	void tick() override;
	void postTick() override;
};

} // end namespace sgde