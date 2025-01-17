#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>


template <typename T>
class Array{

    private:
        T *_elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int  n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        class OutOfBoundsExeption : public std::exception
        {
            public:
            const char *what() const throw()
            {
                return ("Cannot access array: Out of bounds");
            }
        };

        T& operator[](int index) const;
        unsigned int size(void);
};

template <class T>
Array<T>::Array()
{
    _elements = new T[0];
    _size = 0;
}

template <class T>
Array<T>::Array(unsigned int  n)
{
    _elements = new T[n];
    _size = n;
}

template <class T>
Array<T>::Array(const Array &other)
{
    _elements = new T[other._size];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if(this != &other)
    {
        delete[] _elements;
        _elements = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }
    return (*this);
}

template <class T>
Array<T>::~Array()
{
    delete[] _elements;
}

template <class T>
T& Array<T>::operator[](int index) const
{
    if (index < 0 || (unsigned int)index >= _size)
        throw OutOfBoundsExeption();
    else
        return _elements[index];
}


template <class T>
unsigned int Array<T>::size(void)
{
    return _size;
}

#endif
