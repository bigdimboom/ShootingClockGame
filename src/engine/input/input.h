// input.h
#pragma once
#include "../scene/itickable.h"

namespace hcti
{




class Input : public hcts::ITickable
{
private:

	struct _KeyState
	{
		bool isPressed;
		bool wasPressed;
	}; // a record for key state 

	_KeyState d_keyStates[(int)InputType::INPUT_COUNT];
	// key states.

	// CONSTRUCTORS
	// disable all constructors in a singleton class.
	Input();
	// default constructor.
	Input(const Input &) = delete;
	Input(Input &&) = delete;

	// OPERATOR OVERLOADS
	// disable assignment in a singleton class.
	Input& operator = (const Input &) = delete;
	Input& operator = (Input &&) = delete;

public:
	// ACCESSORS
	static Input& inst();
	// access singleton thrpugh this.
	bool isDown(InputType type);
	  // is current state down.
	bool isUp(InputType type);
	  // is current state up.
	bool wasPressed(InputType type);
	  // was down and is now up.

	// MEMBER FUNCTIONS
	void preTick() override;
	  // Poll input state at this point, setup internal state.
	void tick() override;

};

} //end namespace hcti