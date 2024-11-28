#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), name("Unknown")
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
    std::cout << "An unknown DiamondTrap has been created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	ClapTrap::name = name + "_clap_name";
	DiamondTrap::name = name;
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	std::cout << "DiamondTrap "<< name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :ClapTrap(other)
{
	std::cout << "DiamondTrap " << name << " has been copied." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) 
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name =  " << ClapTrap::name << ", DiamondTrap name =  " << DiamondTrap::name <<"." << std::endl;
}
