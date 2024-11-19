#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <map>

class Fixed
{
	private:
		int RawBits;
		static int const bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed&);
		~Fixed(void);
		Fixed &operator=(const Fixed&);
		int getRawBits(void);
		void setRawBits(int NewValue);
};

#endif

