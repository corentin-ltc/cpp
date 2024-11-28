#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	health = 100;
	energy = 100;
	damage = 30;
    std::cout << "An unknown FragTrap has been created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap "<< name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) :ClapTrap(other)
{
	std::cout << "FragTrap " << name << " has been copied." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " want's to dab you up." << std::endl;
}