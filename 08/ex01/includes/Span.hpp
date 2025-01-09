#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
    private:
        std::vector<int> _vec;
        unsigned int _size_max;
    public:
		Span();
		Span(unsigned int size_max);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);      
        class TooManyElementsException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Too many elements";
                }
        };
        class NotEnoughElementsException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Not enough elements";
                }
        };
        int shortestSpan();
        int longestSpan();
        void addNumber(int nb);
    
};