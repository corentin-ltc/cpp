
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <Weapon.hpp>

class HumanA{
	private:
		Weapon &weapon;
		std::string name;
	public:
		HumanA(std::string new_name, Weapon &new_weapon);
		void attack();
};

#endif