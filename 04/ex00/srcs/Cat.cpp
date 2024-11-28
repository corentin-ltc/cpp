#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() : Animal("Undefined")
{
	cout << "Cat default constructor called." << endl;
}


Cat::Cat(std::string type) : Animal(type)
{
	cout << "Cat type constructor called." << endl;
}

Cat::Cat(const Cat &other) : Animal(other.type)
{
	cout << "Cat copy constructor called." << endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	cout << "Cat destructor called." << endl;
}

void const Cat::makeSound()
{
	cout << "Miaw miaw" << endl;
}
