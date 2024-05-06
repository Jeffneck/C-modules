#include <iostream>
#include "ClapTrap.hpp"

int main() {
    std::cout << "\n\n---Création d'un objet ClapTrap avec le constructeur par défaut---\n" << std::endl;
    ClapTrap claptrap1;
    claptrap1.displayStatus();
    
    std::cout << "\n\n---Création d'un objet ClapTrap avec le constructeur prenant un nom en paramètre---\n" << std::endl;
    ClapTrap claptrap2("Bob");
    claptrap2.displayStatus();
    
    std::cout << "\n\n---Copie de l'objet claptrap2 dans un nouvel objet claptrap3---\n" << std::endl;
    ClapTrap claptrap3(claptrap2);
    claptrap3.displayStatus();
    

    claptrap1.beRepaired(2);
    claptrap1.displayStatus();

    std::cout << "\n\n---Utilisation de la méthode attack sur l'objet claptrap1---\n" << std::endl;
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

    std::cout << "\n\n---Utilisation de la méthode takeDamage sur l'objet claptrap1---\n" << std::endl;
    claptrap1.takeDamage(5);
    claptrap1.displayStatus();
    claptrap1.takeDamage(9);
    claptrap1.displayStatus();
    claptrap1.attack("Enemy");
    claptrap1.takeDamage(3);
    claptrap1.displayStatus();

    std::cout << std::endl; 
    return 0;
}