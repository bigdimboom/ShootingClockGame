// character.h
#pragma once
#include "pawn.h"
#include "asprite.h"
#include <vector>

namespace hctg
{

class Character : public Pawn
{
protected:
	ASprite* d_sprite;
public:
	// CONSTRUCTORS
	Character(hctm::Point2f pos = hctm::Point2f(0.0f, 0.0f),
			  hctm::Point2f vel = hctm::Point2f(0.0f, 0.0f));
	Character(const Character & other);
	Character(Character && other);

	// ASSIGNMENT OVERLOADS
	Character& operator = (const Character & other);
	Character& operator = (Character && other);

	virtual ~Character();

	//ACCESSORS
	ASprite* sprites();

	// MEMBER FUNCTIONS
	void attachSprite(ASprite* sprite);
	void removeSprite();

	virtual void preTick() override;
	virtual void tick() override;
};

//ACCESSORS
inline
ASprite* Character::sprites()
{
#ifdef _DEBUG
	std::cerr << "Sprite is NULL.\n";
#endif
	return d_sprite;
}

}// end namespace hctg

