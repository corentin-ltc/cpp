#include "FragTrap.hpp"

int main() {
    FragTrap scav("Guardian");
    ClapTrap test("Test");
	
    scav.attack("Enemy");
    test.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
	scav.highFivesGuys();



    return 0;
}
