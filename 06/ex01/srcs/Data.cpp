#include "Data.hpp"

using std::cout;
using std::endl;

Data::Data() : name("Undefined"){}


Data::Data(std::string name) : name(name){}

Data::Data(const Data &other) : name(other.name){}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
		name = other.name;
	return *this;
}

Data::~Data(){}


std::string Data::getName() const
{
	return this->name;
}
