#include <iostream>
#include "Cat.h"

Cat::Cat()
{
	//std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(float health):Pet(health)
{

}

void Cat::MakeSound()
{
	std::cout << "meow" << std::endl;
}

void Cat::SetOwnerDied()
{

}
