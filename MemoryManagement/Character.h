#pragma once
#include <iostream>


class Character
{
public:
	//default constructor
	Character();
	//constructor that takes arguments
	Character(float health);
	Character(float health, int& numOfRefer);
	//copy constructor
	Character(const Character& );
	//copy assignment constructor
	Character& operator=(const Character&);
	//move constructor
	Character(Character&&) noexcept;
	//move assignmnet constructor
	Character& operator=(Character&&) noexcept;
	//destructor
	virtual~Character();

	/*
	//move and copy assignemnt constructor with swap
	Character& operator=(Character);
	*/

protected:

	float health;
	int* numOfReference;

};

