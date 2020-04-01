#include "Pet.h"
#include "Player.h"
#include <iostream>

Pet::Pet() : health(50)
{
	std::cout << "Pet constructor called" << std::endl;
}

Pet::Pet(float health) : health(health)
{
}

Pet::~Pet()
{
	
}
