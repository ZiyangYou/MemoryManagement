#include <iostream>
#include <memory>
#include "Player.h"
#include "Character.h"
#include "Pet.h"
#include "Cat.h"

int main()
{
	//create a player with 100 health and a dog as pet
	std::unique_ptr<Player> u1(new Player(100, PetType::DOG));//create a unique pointer; it points at a player object allocated with new keyword
	std::cout << "u1 print called." << std::endl;
	u1->print();
	std::weak_ptr<Player> w1; // create a null weak pointer points at object of Player type.
	//shared_printer
	{
		//pass the ownership of the player object from unique pointer to a shared pointer
		std::shared_ptr<Player> p1(u1.release());//reference count 1
		std::cout << "p1 print called." << std::endl;
		p1->print();
		std::cout << "the current reference count of the shared pointer p1: " << p1.use_count() << std::endl;

		//make a copy of shared pointer p1
		{
			std::shared_ptr<Player> p2(p1);//reference count 2
			w1 = p2; // weak pointer now points to p1, but reference count of p1 does not increase.
			std::cout << "p2 print called." << std::endl;
			p2->print();
			std::cout << "the current reference count of the shared pointer p2 and p1: " << p2.use_count() << std::endl;
		}//end of this scope, p2 deleted; sharedpointer reference count reduce by 1

		if (std::shared_ptr<Player> tmpp = w1.lock()) // true if tmpp is not null
		{
			std::cout << "tmpp print called." << std::endl;
			tmpp->print();
			std::cout << "the current reference count of the shared pointer (p1 and p2) that share ownership with w1: " << tmpp.use_count() << std::endl;
		}
		else
		{
			std::cout << "the object that w1 points to is null" << std::endl;
		}
	}//end of this scope, p1 deleted; sharedpointer reference count reduce by 1; the memory to which p1 points to was freed
	if (std::shared_ptr<Player> tmpp = w1.lock()) // true if tmpp is not null
	{
		std::cout << "tmpp print called." << std::endl;
		tmpp->print();
		std::cout << "the current reference count of the shared pointer (p1 and p2) that share ownership with w1: " << tmpp.use_count() << std::endl;
	}
	else
	{
		std::cout << "tmpp print called." << std::endl;
		std::cout << "the object that w1 points to is null" << std::endl;
		std::cout << "the current reference count of the shared pointer (p1 and p2) that share ownership with w1: " << tmpp.use_count() << std::endl;
	}
	
	//smart pointer with dynamic array
	{
		//using unique pointer
		std::unique_ptr<Player[]> uniquePlayerArray(new Player[5]);
		uniquePlayerArray.reset(); // the dynamic array automatically use delete[] to free the memory
		//using shared pointer
		std::shared_ptr<Player[]> sharedPlayerArray(new Player[5], [](Player* p) {delete[] p; });// since shared pointer does not suppor managing dynamic array automatically, we need to provide a delete function
		sharedPlayerArray.reset();// using the lambda function to delete the memory
	}
}
