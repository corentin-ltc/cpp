#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), health(10), energy(10), damage(0)
{
    std::cout << "An unknown ClapTrap has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), damage(0)
{
	std::cout << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), health(other.health), energy(other.energy), damage(other.damage)
{
	std::cout << "ClapTrap " << name << " has been copied." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " has been destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
	if (this != &other)
	{
		name = other.name;
		damage = other.damage;
		energy = other.energy;
		health = other.health;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " does not have enough energy points to attack." << std::endl;
		return ;
	}
	
	if (health <= 0)
	{
		std::cout << "ClapTrap " << name << " does not have enough hit points to attack." << std::endl;
		return ;
	}
	energy--;	
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " points of damage" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " does not have enough energy points to be repaired." << std::endl;
		return ;
	}
	if (health <= 0)
	{
		std::cout << "ClapTrap " << name << " does not have enough hit points to be rapaired." << std::endl;
		return ;
	}
	energy--;
	health += amount;
	std::cout << "ClapTrap " << name << " now has " << health << " hit points" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	health -= amount;
	if (health < 0)
		health = 0;
	std::cout << "ClapTrap " << name << " has been attacked now have " << health << " hit points remaining" << std::endl;
} 