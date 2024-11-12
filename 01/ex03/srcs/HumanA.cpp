#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) :
	weapon(new_weapon),
	name(new_name)
	{}


void HumanA::attack(){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}