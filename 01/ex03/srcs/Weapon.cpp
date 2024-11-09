#include "Weapon.hpp"

Weapon::Weapon()
{
	return;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

std::string *Weapon::getType (){
	return (&this->type);
}

void Weapon::setType (std::string new_type){
	this->type = new_type;
	std::cout << this->type << std::endl;
}
