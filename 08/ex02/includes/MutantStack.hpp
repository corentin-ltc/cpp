#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>


template <typename T>
class MutantStack : public std::stack
{
    public:

        using std::stack<T>::c;

		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator=(const MutantStack &other);      

};

template <class T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template <class T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <class T>
MutantStack<T>::~MutantStack(){}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return (*this);
}
