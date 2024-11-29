#include "WrongDog.hpp"

using std::cout;
using std::endl;

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	cout << "WrongDog default constructor called." << endl;
}


WrongDog::WrongDog(std::string type) : WrongAnimal(type)
{
	cout << "WrongDog type constructor called." << endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other.type)
{
	cout << "WrongDog copy constructor called." << endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongDog::~WrongDog()
{
	cout << "WrongDog destructor called." << endl;
}

void WrongDog::makeSound() const
{
	cout << "Waf" << endl;
}
