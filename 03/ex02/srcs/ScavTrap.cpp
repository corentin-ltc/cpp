#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	health = 100;
	energy = 50;
	damage = 20;
    std::cout << "An unknown ScavTrap has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap "<< name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) :ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " has been copied." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
}
