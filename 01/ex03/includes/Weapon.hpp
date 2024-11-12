#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>
# include <cstring>

class Weapon{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		void setType (std::string type);
		std::string getType ();
};

#endif