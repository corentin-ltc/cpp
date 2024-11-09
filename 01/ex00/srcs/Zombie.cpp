#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "New zombie created." << std::endl;
}
Zombie::~Zombie()
{
	std::cout << this->name << " destroyed." << std::endl;
}

void Zombie::set_name(std::string name){
	this->name = name;
}

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}