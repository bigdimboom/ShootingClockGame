// event_bus.h
// A singleton wrapper for EventDispatcher 
// you can define your own EventBus
#pragma once
#include "event_dispatcher.h"
#include "basic_event.h"

namespace hcte
{

#define EVENT_QUEUE_SIZE 1000

class EventBus : public hcts::ITickable
{
private:
	unsigned int d_qSize;
	EventDispatcher d_evDispatcher;
	std::vector<BasicEvent> d_eventQ;
	  // if it is an online game, then it is better define an Event Object
	  // instead of IEvent interface. Becuase it is good for serilization.

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
	bool enQueueEvent(const BasicEvent& ev);
	  // return false if queue is full, event bus collects memory
	bool deQueueEvent(const BasicEvent& ev);
	  // return  false if the event is not there, user collects memory

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