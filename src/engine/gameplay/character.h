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
	std::vector<ASprite*> d_sprites;
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
	const std::vector<ASprite*>& sprites() const;

	// MEMBER FUNCTIONS
	void attachSprites(ASprite* sprite);
	void removeSprites(ASprite* sprite);

	virtual void preTick() override;
	virtual void tick() override;
};

}// end namespace hctg

