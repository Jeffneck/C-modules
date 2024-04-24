// #include <iostream>
// #include <string>
#include "Zombie.hpp"

int main() {
    std::cout << "---- Create a zombie : " << std::endl;
    Zombie z1;
    z1.announce();
    std::cout << "\n\n\n";


    std::cout << "---- Create a named zombie : " << std::endl;
    Zombie z2("*Francis la saucisse*");
    z2.announce();
    std::cout << "\n\n\n";

    std::cout << "---- Allocate a new Zombie : " << std::endl;
    Zombie* z3;
    try {
        z3 = newZombie("*Zombaloco*");
    }
    catch (const std::bad_alloc& err)
    {
        std::cerr << "Allocation with newZombie failed :" << err.what() << std::endl;
        return (1);
    }
    z3->announce();
    delete z3;
    std::cout << "\n\n\n";

    std::cout << "---- BONUS : show error when allocation didn't work : " << std::endl;
    Zombie* z4;
    try {
         // Tentative d'allouer une grande quantité de mémoire qui dépasse la capacité disponible
        z4 = (Zombie *)new int[1000000000000]; // Tentative d'allouer un trillion d'entiers (probablement trop grande pour être allouée)
    }
    catch (const std::bad_alloc& err)
    {
        std::cerr << "Allocation with newZombie failed :" << err.what() << std::endl;
    }
    std::cout << "\n\n\n";
    return (0);
}