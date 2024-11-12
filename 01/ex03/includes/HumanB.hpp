#include <Weapon.hpp>

class HumanB{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &new_weapon);
};