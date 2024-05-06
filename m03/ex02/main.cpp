#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "\n---Création d'un objet FragTrap avec le constructeur par défaut---\n" << std::endl;
    FragTrap fragtrap1;
    fragtrap1.displayStatus();
    
    std::cout << "\n---Création d'un objet FragTrap avec le constructeur prenant un nom en paramètre---\n" << std::endl;
    FragTrap fragtrap2("Bob");
    fragtrap2.displayStatus();
    
    std::cout << "\n---Copie de l'objet fragtrap2 dans un nouvel objet fragtrap3---\n" << std::endl;
    FragTrap fragtrap3(fragtrap2);
    fragtrap3.displayStatus();
    

    fragtrap1.beRepaired(2);
    fragtrap1.displayStatus();

    std::cout << "\n---Utilisation de la méthode attack sur l'objet fragtrap1---\n" << std::endl;
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

    std::cout << "\n---Utilisation de la méthode takeDamage sur l'objet fragtrap1---\n" << std::endl;
    fragtrap1.takeDamage(5);
    fragtrap1.displayStatus();
    fragtrap1.takeDamage(9);
    fragtrap1.displayStatus();
    fragtrap1.takeDamage(3);
    fragtrap1.displayStatus();


    std::cout << std::endl; 

    return 0;
}