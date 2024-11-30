#include "Cat.hpp"

using std::cout;
using std::endl;


Cat::Cat() : Animal("Cat")
{
	cout << "Cat default constructor called." << endl;
	brain = new Brain;
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
	delete brain;
	cout << "Cat destructor called." << endl;
}

void Cat::makeSound() const
{
	cout << "Miaw miaw" << endl;
}
