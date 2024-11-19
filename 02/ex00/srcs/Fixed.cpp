#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed() : RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &other)
		RawBits = other.RawBits;
	return (*this);
};

Fixed::Fixed(const Fixed &other) : RawBits(other.RawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	
};

void Fixed::setRawBits(int newValue)
{
	RawBits = newValue;
}
int	Fixed::getRawBits()
{
	std::cout << "GetRawBits member function called" << std::endl;
	return this->RawBits;
}