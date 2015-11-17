// basic_event.h
#pragma once
#include "ievent.h"

namespace hcte
{

static const std::string K_NULL = "_NUL_";

class BasicEvent : public IEvent
{
private:
	std::string d_msg;
	EventType d_type; // USE GUID
public:
	// CONSTRUCTORS
	BasicEvent(EventType guid, std::string message = K_NULL);
	BasicEvent(const BasicEvent &);
	BasicEvent(BasicEvent &&);

	// ASSIGNMENT OVERLOADS
	BasicEvent& operator=(const BasicEvent &);
	BasicEvent& operator=(BasicEvent &&);

	// DESTRUCTORS
	~BasicEvent();

	// ACCESSORS
	virtual const EventType & type() const;
	virtual const std::string message() const;

};

// CONSTRUCTORS
inline
BasicEvent::BasicEvent(EventType guid, std::string message)
 : d_type(guid)
 , d_msg(message)
{
}

inline
BasicEvent::BasicEvent(const BasicEvent & other)
: d_type(other.d_type)
, d_msg(other.d_msg)
{
}

inline
BasicEvent::BasicEvent(BasicEvent && other)
: d_type(std::move(other.d_type))
, d_msg(std::move(other.d_msg))
{
}

// ASSIGNMENT OVERLOADS
inline
BasicEvent& BasicEvent::operator = (const BasicEvent & other)
{
	if (this != &other)
	{
		d_type = other.d_type;
		d_msg = other.d_msg;
	}
	return *this;
}

inline
BasicEvent& BasicEvent::operator = (BasicEvent && other)
{
	if (this != &other)
	{
		d_type = std::move(other.d_type);
		d_msg = std::move(other.d_msg);
	}
	return *this;
}

// DESTRUCTORS
inline
BasicEvent::~BasicEvent()
{
}

// ACCESSORS
inline
const EventType& BasicEvent::type() const
{
	return d_type;
}

inline
const std::string BasicEvent::message() const
{
	return d_msg;
}

} // end namespace hcte