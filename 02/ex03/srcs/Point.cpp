#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &fixedX, const Fixed &fixedY) : x(fixedX), y(fixedY) {}

Point::Point(const float floatx, const float floaty) : x(Fixed(floatx)), y(Fixed(floaty)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        std::cerr << "Cannot assign to a Point because its members are const." << std::endl;
    }
    return *this;
}


Fixed Point::get_x(void) const
{
    return x;
}

Fixed Point::get_y(void) const
{
    return y;
}

Point::~Point() {}