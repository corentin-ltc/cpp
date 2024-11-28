#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Booba");
    ClapTrap clap2("KobaLaD");

    clap1.attack("Gazo");
    clap2.takeDamage(3);

    clap2.attack("LilBaby");
    clap1.takeDamage(5);

    clap1.beRepaired(4);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);
    clap2.beRepaired(2);

    clap1.attack("Test");
    clap2.takeDamage(4);

    return 0;
}
