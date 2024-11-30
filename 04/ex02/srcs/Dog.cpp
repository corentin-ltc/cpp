#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() : Animal("Dog")
{
	cout << "Dog default constructor called." << endl;
	brain = new Brain;
}


Dog::Dog(std::string type) : Animal(type)
{
	cout << "Dog type constructor called." << endl;
}

Dog::Dog(const Dog &other) : Animal(other.type)
{
	cout << "Dog copy constructor called." << endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	delete brain;
	cout << "Dog destructor called." << endl;
}

void Dog::makeSound() const
{
	cout << "Waf" << endl;
}
