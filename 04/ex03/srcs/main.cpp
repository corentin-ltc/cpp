#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main() {
    MateriaSource *materiaSource = new MateriaSource();

    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());
    materiaSource->learnMateria(new Ice());

    ICharacter *me = new Character("Player");
    if (!me)
        std::cout << "Allocation failed" << std::endl;
    AMateria *ice = materiaSource->createMateria("ice");
    AMateria *cure = materiaSource->createMateria("cure");

    if (ice)
        std::cout << "Created Materia: " << ice->getType() << std::endl;
    else
        std::cout << "Failed to create ice Materia" << std::endl;

    if (cure)
        std::cout << "Created Materia: " << cure->getType() << std::endl;
    else
        std::cout << "Failed to create cure Materia" << std::endl;

    me->equip(ice);
    me->equip(cure);

    ICharacter *bob = new Character("Bob");
    me->use(0, *bob);  
    me->use(1, *bob);  

    me->unequip(0);    
    me->use(0, *bob);  

  
    me->use(1, *bob);

    delete bob;
    delete me;
    delete materiaSource;
    delete ice;  


    return 0;
}
