// event_bus.h
// A singleton wrapper for EventDispatcher 
// or should I call it EventManager.
#pragma once
#include "event_dispatcher.h"

namespace hcte
{

#define EVENT_QUEUE_SIZE 1000

class EventBus : public hcts::ITickable
{
private:
	unsigned int d_qSize;
	EventDispatcher d_evDispatcher;
	std::vector<const IEvent*> d_eventQ;

	// DELETED
	EventBus();
	EventBus(const EventBus &) = delete;
	EventBus(EventBus &&) = delete;
	EventBus& operator = (const EventBus &) = delete;
	EventBus& operator = (EventBus &&) = delete;
public:
	//ACCESSORS
	static EventBus& inst();

	// MUTATORS
	void setQueueSize(unsigned int size);

	// MEMBER FUNCTIONS
	bool enQueueEvent(const IEvent & ev);
	  // return false if queue is full.
	bool deQueueEvent(const IEvent & ev);
	  // return  false if the event is not there.

	void registerListener(const IEvent & ev,
						  EventListenerCallbacksPtr listener);
	void deRegisterListener(const IEvent & ev,
						  EventListenerCallbacksPtr listener);

	void triggerEvent(const IEvent & ev);
	  // trigger event at once without adding to the event queue.

	void preTick() override;
	void tick() override;
};

} // end namespace sgde