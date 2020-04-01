#include "Character.h"

//default constructor
Character::Character(): health(100), numOfReference(new int(1)){}
//constructors that take arguments
Character::Character(float health) : health(health), numOfReference(new int(1)){}
Character::Character(float health, int& numOfRefer) : health(health), numOfReference(&numOfRefer){}

//copy constructor
Character::Character(const Character& c) : health(c.health), numOfReference(c.numOfReference){}
//copy assignment constructor
Character& Character::operator=(const Character& c)
{
	(*c.numOfReference)++;
	if (--*numOfReference == 0)
	{
		delete numOfReference;
	}
	numOfReference = c.numOfReference;
	return *this;
}
//move constructor
Character::Character(Character&& c) noexcept : health(c.health), numOfReference(c.numOfReference)
{
	c.numOfReference = nullptr;
}
//move assignment constructor
Character& Character::operator=(Character&& c) noexcept
{
	if (this != &c)
	{
		health = c.health;
		numOfReference = c.numOfReference;
		c.numOfReference = nullptr;
	}
	return *this;
}

/*
*copy and move assignment constructor using swap function
*this handles both copy and move assignment constructors and as well as self-assignment.
Character& Character::operator=(Character c)
{
	std::swap(*this, c);
	return *this;
}
*/

Character::~Character()
{
	if (--(*numOfReference) == 0)
	{
		delete numOfReference;
	}
}
