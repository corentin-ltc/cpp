#include "Zombie.hpp"

int main(void)
{
	Zombie* alien;

	randomChump("Marylin");
	alien = newZombie("POOK");
	delete alien;
}