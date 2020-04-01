#pragma once
#include "Pet.h"

class Cat :	public Pet
{
public:
	Cat();
	Cat(float health);
	void MakeSound()override;
	void SetOwnerDied()override;
};

