#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie newZombie;

	newZombie.set_name(name);
	newZombie.announce();
}