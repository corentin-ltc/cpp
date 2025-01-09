#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

class ElementNotFoundException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Element not found";
        }
};

template <typename T>
int easyfind(T& container, int value)
{
    typename T::iterator result = std::find(container.begin(), container.end(), value);
    if (result != container.end())
        return *result;
    else
        throw ElementNotFoundException();
}

