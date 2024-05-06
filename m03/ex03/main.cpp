#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n\n---Création d'un objet DiamondTrap avec le constructeur par défaut---\n" << std::endl; 
    DiamondTrap diamond1("BlingBling");

    std::cout << "\n\n---Test des methodes heritees---" << std::endl; 
    diamond1.whoAmI();
    diamond1.highFivesGuys();
    diamond1.guardGate();

    diamond1.displayStatus();
    diamond1.beRepaired(2);
    diamond1.displayStatus();

    std::cout << "\n\n---Utilisation de la méthode attack sur l'objet diamond1---\n" << std::endl; 
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.displayStatus();
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");
    diamond1.attack("Enemy");

    diamond1.beRepaired(2);

    diamond1.displayStatus();

    std::cout << "\n\n---Utilisation de la méthode takeDamage sur l'objet diamond1---\n" << std::endl; 
    diamond1.takeDamage(5);
    diamond1.displayStatus();
    diamond1.takeDamage(9);
    diamond1.displayStatus();
    diamond1.takeDamage(3);
    diamond1.displayStatus();

    std::cout << std::endl; 

    return 0;
}