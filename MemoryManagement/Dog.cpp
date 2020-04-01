#include "Dog.h"
#include <iostream>

Dog::Dog()
{
}

Dog::Dog(float health):Pet(health)
{
}

void Dog::MakeSound()
{
	std::cout << "howl" << std::endl;
}

void Dog::SetOwnerDied()
{
	
}
