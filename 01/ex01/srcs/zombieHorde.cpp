#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *newZombies;

	if (N < 1){
		std::cout << "N can't be negative." << std::endl;
		exit(EXIT_FAILURE);
	}
	newZombies = new Zombie[N];
	while (N > 0)
		newZombies[--N].set_name(name);
	return (newZombies);
}