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
        class IncorrectRangeException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Can't add this range in the container";
                }
        };
        int shortestSpan();
        int longestSpan();
        void addNumber(int nb);
        void addNumbers(int start, int end);
    
};