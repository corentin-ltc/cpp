#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
	    int RawBits; 
	    static const int fractionalBits = 8;
	public:
	    Fixed();
	    Fixed(const int intVal);
	    Fixed(const float floatVal);
	    Fixed(const Fixed &other);
	    Fixed &operator=(const Fixed &other);
	    ~Fixed();
	    float toFloat(void) const;
	    int toInt(void) const;
	    int getRawBits(void) const;
	    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
