#pragma once
#include "Character.h"
enum class PetType { CAT, DOG };

class Player :	public Character
{
public:
	//default constructor
	Player();
	//constructor that takes arguments
	Player(float health, PetType petT);
	//copy constructor
	Player(const Player&);
	//copy assignment constructor
	Player& operator=(const Player&);

	//deconstructor
	~Player()override;

private:
	class Pet* playerPet;
	PetType playerPetType;
};

