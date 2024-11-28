#include "Animal.hpp"

using std::cout;
using std::endl;

Animal::Animal() : type("Undefined")
{
	cout << "Animal default constructor called." << endl;
}


Animal::Animal(std::string type) : type(type)
{
	cout << "Animal type constructor called." << endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	cout << "Animal copy constructor called." << endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	cout << "Animal destructor called." << endl;
}
std::string Animal::getType()
{
	return type;
}