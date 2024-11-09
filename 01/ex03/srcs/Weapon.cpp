#include "Weapon.hpp"

std::string Weapon::getType (){
	return (this->type);
}

std::string Weapon::setType (std::string type){
	this->type = type;
}