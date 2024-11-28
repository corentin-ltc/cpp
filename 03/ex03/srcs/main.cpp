#include "DiamondTrap.hpp"

int main() {
    DiamondTrap scav("Guardian");
	
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
	scav.whoAmI();

    return 0;
}
