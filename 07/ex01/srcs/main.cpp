#include "iter.hpp"
#include <iostream>

void randomFunction(int &a)
{
    std::cout << a << std::endl;
}

void displaySTR(std::string &str)
{
    std::cout << str << std::endl;
}


int main( void )
{

    std::string strs[5] = {
	"Bonjour",
	"je",
	"m'appelle",
	"Corentin",
    "LT"
	};
	iter(strs, 5, displaySTR);
    int array[] = {1, 2, 3, 4};
    iter(array, 4, randomFunction);
    return 0;
}