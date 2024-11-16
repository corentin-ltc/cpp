#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		harlos;
	int			priority;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments," << std::endl;
		exit(EXIT_FAILURE);
	}
	level = argv[1];

	if (level == "DEBUG")
		priority = 0;
	else if (level == "INFO")
		priority = 1;
	else if (level == "WARNING")
		priority = 2;
	else if (level == "ERROR")
		priority = 3;
	else
		priority = -1;
	
	switch (priority){
	case (0):
		harlos.complain("debug");
	case (1):
		harlos.complain("info");
	case (2):
		harlos.complain("warning");
	case (3):
		harlos.complain("error");
		break;
	default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}