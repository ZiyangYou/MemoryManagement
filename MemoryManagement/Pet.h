#pragma once
//abstract Pet class
#include <vector>

class Pet
{
public:
	//default constructor
	Pet();
	//constructor that takes arguments
	Pet(float health);
	//deconstructor
	~Pet();

	//copy constructor delete
	Pet(const Pet&) = delete;
	//copy assignment constructor delete
	Pet& operator= (const Pet&) = delete;

protected:
	virtual void MakeSound() = 0;
	virtual void SetOwnerDied() = 0;
	float health;
	std::vector<class Player*> Owner;
};

