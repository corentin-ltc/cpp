#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        using std::stack<T>::c;

		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator=(const MutantStack &other);      

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return c.begin(); }
    iterator end() { return c.end(); }
    const_iterator begin() const { return c.begin(); }
    const_iterator end() const { return c.end(); }
    reverse_iterator rbegin() { return c.rbegin(); }
    reverse_iterator rend() { return c.rend(); }
    const_reverse_iterator rbegin() const { return c.rbegin(); }
    const_reverse_iterator rend() const { return c.rend(); }
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
