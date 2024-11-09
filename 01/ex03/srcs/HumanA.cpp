#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon new_weapon)
{
	this->name = new_name;
	this->weapon = new_weapon;
}

void HumanA::attack(){
	std::cout << this->name << " attacks with their " << *this->weapon.getType() << std::endl;
}