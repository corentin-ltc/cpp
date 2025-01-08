#include "iter.hpp"
#include <iostream>

void randomFunction(int a)
{
    std::cout << a << std::endl;
}

void displaySTR(std::string str)
{
    std::cout << str << std::endl;
}


int main( void )
{

    int array[] = {1, 2, 3, 4};
    iter(array, 4, randomFunction);
    std::string strs[3] = {
	"Hola",
	"Que",
	"Tal ?"
	};
	iter(strs, 3, displaySTR);
    return 0;
}