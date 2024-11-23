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

    
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    
    Fixed &operator++();   
    Fixed operator++(int); 
    Fixed &operator--();   
    Fixed operator--(int); 
};


std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
