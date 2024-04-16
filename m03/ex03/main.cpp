#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    // Création d'un objet DiamondTrap avec le constructeur par défaut
    DiamondTrap diamond1("BlingBling");

    //test des methodes heritees
    diamond1.whoAmI();
    diamond1.highFivesGuys();
    diamond1.guardGate();

    diamond1.displayStatus();
    diamond1.beRepaired(2);
    diamond1.displayStatus();

    // Utilisation de la méthode attack sur l'objet diamond1
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

    // Utilisation de la méthode takeDamage sur l'objet diamond1
    diamond1.takeDamage(5);
    diamond1.displayStatus();
    diamond1.takeDamage(9);
    diamond1.displayStatus();
    diamond1.takeDamage(3);
    diamond1.displayStatus();


    diamond1.displayStatus();
    return 0;
}