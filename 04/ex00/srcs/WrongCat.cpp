#include "WrongCat.hpp"

using std::cout;
using std::endl;

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "WrongCat default constructor called." << endl;
}


WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	cout << "WrongCat type constructor called." << endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type)
{
	cout << "WrongCat copy constructor called." << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called." << endl;
}

void WrongCat::makeSound() const
{
	cout << "Miaw miaw" << endl;
}
