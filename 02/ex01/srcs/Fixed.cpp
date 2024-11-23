#include "Fixed.hpp"

Fixed::Fixed() : RawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    this->RawBits = intVal << fractionalBits;
}

Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    this->RawBits = static_cast<int>(roundf(floatVal * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) : RawBits(other.RawBits) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->RawBits = other.RawBits;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->RawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->RawBits >> fractionalBits;
}

int Fixed::getRawBits(void) const {
    return this->RawBits;
}

void Fixed::setRawBits(int const raw) {
    this->RawBits = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
