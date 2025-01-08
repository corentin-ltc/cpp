#include "Array.hpp"

template <class T>
Array::Array()
{
    _elements = new T[0];
    size = 0;
}

template <class T>
Array::Array(unsigned int  n)
{
    _elements = new T[n];
    size = n;
}

template <class T>
Array::Array(const Array &other)
{
    _elements = new T[other.size];
    _size = other._size;
    for (int i = 0; i < size; i++)
        _elements[i] = other._elements[i];
}

template <class T>
Array::Array &operator=(const Array &other)
{
    if(this != other)
    {
        _elements = new T[other.size];
        _size = other._size;
        for (int i = 0; i < size; i++)
            _elements[i] = other._elements[i];
    }
    return (*this);
}

template <class T>
Array::~Array()
{
    delete[] _elements;
}