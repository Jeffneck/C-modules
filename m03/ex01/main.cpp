#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "\n\n---Création d'un objet ScavTrap avec le constructeur par défaut---\n" << std::endl;
    ScavTrap scavtrap1;
    scavtrap1.displayStatus();
    
    std::cout << "\n\n---Création d'un objet ScavTrap avec le constructeur prenant un nom en paramètre---\n" << std::endl;
    ScavTrap scavtrap2("Bob");
    scavtrap2.displayStatus();
    
    std::cout << "\n\n---Copie de l'objet scavtrap2 dans un nouvel objet scavtrap3---\n" << std::endl;
    ScavTrap scavtrap3(scavtrap2);
    scavtrap3.displayStatus();
    scavtrap1.beRepaired(2);
    scavtrap1.displayStatus();

    std::cout << "\n\n---Utilisation de la méthode attack sur l'objet scavtrap1---\n" << std::endl;
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.displayStatus();
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.attack("Enemy");
    scavtrap1.beRepaired(2);
    scavtrap1.displayStatus();

    std::cout << "\n\n---Utilisation de la méthode takeDamage sur l'objet scavtrap1---\n" << std::endl;
    scavtrap1.takeDamage(5);
    scavtrap1.displayStatus();
    scavtrap1.takeDamage(9);
    scavtrap1.displayStatus();
    scavtrap1.takeDamage(3);
    scavtrap1.displayStatus();

    std::cout << std::endl; 
    return 0;
}