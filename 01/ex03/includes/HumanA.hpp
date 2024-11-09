
#include <Weapon.hpp>

class HumanA{
	private:
		Weapon weapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon new_weapon);
		void attack();
};