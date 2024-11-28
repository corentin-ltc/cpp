#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Guardian");
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    ScavTrap scavCopy(scav);

    ScavTrap scavAssigned;
    scavAssigned = scav;

    return 0;
}
