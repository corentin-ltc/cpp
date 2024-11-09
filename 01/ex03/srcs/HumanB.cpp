#include "HumanB.hpp"

HumanB::HumanB(std::string new_name)
{
	this->name = new_name;
}

void HumanB::attack(){
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon new_weapon)
{
	this->weapon = new_weapon;
}