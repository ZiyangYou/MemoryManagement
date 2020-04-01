#pragma once
#include "Pet.h"

class Dog :	public Pet
{
public:
	Dog();
	Dog(float health);
	void MakeSound()override;
	void SetOwnerDied()override;
};

