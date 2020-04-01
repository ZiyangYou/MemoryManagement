#include "Player.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"

Player::Player() : Character(), playerPet(new Cat())
{
	playerPetType = PetType::CAT;
}

Player::Player(float health, PetType petT) : Character(health)
{
	(petT == PetType::CAT) ? playerPet = new Cat() : playerPet = new Dog();
	playerPetType = petT;
}

//this class with behave like a pointer (copy the object of this class will share data, the copy and original object will use the same underlying data)

//copy constructor
Player::Player(const Player& p) : Character(p.health), playerPetType(p.playerPetType), playerPet(p.playerPet)
{
	numOfReference++;
}

//copy assignment constructor 
Player& Player::operator=(const Player& p)
{
	++(*p.numOfReference);
	if (--(*numOfReference) == 0)
	{
		delete playerPet;
		delete numOfReference;
	}
	playerPet = p.playerPet;
	numOfReference = p.numOfReference;
	playerPetType = p.playerPetType;

	return *this;
}

Player::~Player()
{
	if (--(*numOfReference) == 0)
	{
		delete playerPet;
	}
}
