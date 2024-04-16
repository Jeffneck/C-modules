#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    // Création d'un objet FragTrap avec le constructeur par défaut
    FragTrap fragtrap1;
    fragtrap1.displayStatus();
    
    // Création d'un objet FragTrap avec le constructeur prenant un nom en paramètre
    FragTrap fragtrap2("Bob");
    fragtrap2.displayStatus();
    
    // Copie de l'objet fragtrap2 dans un nouvel objet fragtrap3
    FragTrap fragtrap3(fragtrap2);
    fragtrap3.displayStatus();
    

    fragtrap1.beRepaired(2);
    fragtrap1.displayStatus();

    // Utilisation de la méthode attack sur l'objet fragtrap1
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.displayStatus();
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");
    fragtrap1.attack("Enemy");

    fragtrap1.beRepaired(2);

    fragtrap1.displayStatus();

    // Utilisation de la méthode takeDamage sur l'objet fragtrap1
    fragtrap1.takeDamage(5);
    fragtrap1.displayStatus();
    fragtrap1.takeDamage(9);
    fragtrap1.displayStatus();
    fragtrap1.takeDamage(3);
    fragtrap1.displayStatus();


    fragtrap1.displayStatus();
    return 0;
}