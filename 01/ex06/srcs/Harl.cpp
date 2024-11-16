#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void Harl::info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I've been comingfor years whereas you started working here since last month" << std::endl;
}
void Harl::error(void)
{
	std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)(void)> map = 
	{
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error}
	};
	if (map.find(level) != map.end())
		(this->*map[level])();
	else 
		 std::cout << "Invalid level: " << level << std::endl;
}