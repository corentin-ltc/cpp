#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>


template <typename T>
class MutantStack
{
    private:
        std::stack<T> _stack;
    public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator=(const MutantStack &other);      
        void push(int nb);
        void pop(void);
        int size(void);
        T top(void);
        T* begin(void); 
        T* end(void); 
    
};

template <class T>
MutantStack<T>::MutantStack(){}

template <class T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
    _stack = other._stack;
}
template <class T>
MutantStack<T>::~MutantStack(){}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
        _stack = other._stack;
    return (*this);
}

template <class T>
void MutantStack<T>::push(int nb)
{
    _stack.push(nb);
}

template <class T>
void MutantStack<T>::pop(void)
{
    _stack.pop();
}

template <class T>
int MutantStack<T>::size(void)
{
    return _stack.size();
}

template <class T>
T MutantStack<T>::top(void)
{
    return _stack.top();
}