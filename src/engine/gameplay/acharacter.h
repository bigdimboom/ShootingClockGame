// acharacter.h
#pragma once
#include "apawn.h"
#include "../rendering/idrawable.h"

namespace hctg
{

class ACharacter : public APawn, public hctr::IDrawable
{
private:
	std::vector<hctr::IDrawable *> d_drawables;
	  // can do instance drawing


	// DELETED
	ACharacter(const ACharacter & other) = delete;
	ACharacter(ACharacter && other) = delete;
	ACharacter& operator = (const ACharacter & other) = delete;
	ACharacter& operator = (ACharacter && other) = delete;

public:
	// CONSTRUCTOR
	ACharacter(AController* controller = nullptr);
	// DESTRUCTOR
	~ACharacter();

	// ACCESSORS
	const std::vector<hctr::IDrawable*>& drawables() const;

	// MUTATORS
	void addDrawable(hctr::IDrawable * drawable);
	void removeDrawable(hctr::IDrawable * drawable);

	// MEMBER FUNCTIONS
	virtual void preTick() = 0;
	virtual void tick() = 0;
	virtual void draw() = 0;
};

} // end namespace hctg