#include "Zombie.hpp"

int main(void)
{
	Zombie* alien;

	randomChump("Marylin");
	alien = newZombie("POOK");
	alien->announce();
	delete alien;
}