#include "WrongAnimal.hpp"

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal() : type("Undefined")
{
	cout << "WrongAnimal default constructor called." << endl;
}


WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	cout << "WrongAnimal type constructor called." << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	cout << "WrongAnimal copy constructor called." << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called." << endl;
}

void WrongAnimal::makeSound() const
{
	cout << "Undefined sound" << endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
