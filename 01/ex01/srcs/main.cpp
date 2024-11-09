#include "Zombie.hpp"

int main(void)
{
	Zombie* aliens;
	int n;

	n = 5;
	aliens = zombieHorde(n, "Charlie");
	while (n > 0)
		aliens[--n].announce();
	delete [] aliens;
}