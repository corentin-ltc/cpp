#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie has been created." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << " created." << std::endl;
}
Zombie::~Zombie()
{
	std::cout << this->name << " destroyed." << std::endl;
}

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}
