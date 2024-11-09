#include <iostream>

int main(void)
{
	std::string STR = "HI THIS IS BRAIN";
	std::string *stringPTR = &STR;
	std::string &stringREF = STR;

	std::cout << "Adresse de la string: " << &STR << std::endl;
	std::cout << "Adresse stockee dans stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse stockee dans stringREF: " << &stringREF << std::endl;
	
	std::cout << "Valeur de la string: " << STR << std::endl;
	std::cout << "Valeur pointee par stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur pointee par stringREF: " << stringREF << std::endl;
}