#include "Fixed.hpp"

Fixed::Fixed() : RawBits(0) {}

Fixed::Fixed(const int intVal) {
    this->RawBits = intVal << fractionalBits;
}

Fixed::Fixed(const float floatVal) {
    this->RawBits = static_cast<int>(roundf(floatVal * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) : RawBits(other.RawBits) {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->RawBits = other.RawBits;
    }
    return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &other) const {
    return this->RawBits > other.RawBits;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->RawBits < other.RawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->RawBits >= other.RawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->RawBits <= other.RawBits;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->RawBits == other.RawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->RawBits != other.RawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->RawBits + other.RawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->RawBits - other.RawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->RawBits * other.RawBits) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->RawBits << fractionalBits) / other.RawBits);
    return result;
}

Fixed &Fixed::operator++() {
    this->RawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->RawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->RawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->RawBits--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
