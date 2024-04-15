#include <iostream>
#include "ClapTrap.hpp"

int main() {
    // Création d'un objet ClapTrap avec le constructeur par défaut
    ClapTrap claptrap1;
    claptrap1.displayStatus();
    
    // Création d'un objet ClapTrap avec le constructeur prenant un nom en paramètre
    ClapTrap claptrap2("Bob");
    claptrap2.displayStatus();
    
    // Copie de l'objet claptrap2 dans un nouvel objet claptrap3
    ClapTrap claptrap3(claptrap2);
    claptrap3.displayStatus();
    

    claptrap1.beRepaired(2);
    claptrap1.displayStatus();

    // Utilisation de la méthode attack sur l'objet claptrap1
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.displayStatus();
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");
    claptrap1.attack("Enemy");

    claptrap1.beRepaired(2);

    claptrap1.displayStatus();

    // Utilisation de la méthode takeDamage sur l'objet claptrap1
    claptrap1.takeDamage(5);
    claptrap1.displayStatus();
    claptrap1.takeDamage(9);
    claptrap1.displayStatus();
    claptrap1.takeDamage(3);
    claptrap1.displayStatus();


    claptrap1.displayStatus();
    return 0;
}