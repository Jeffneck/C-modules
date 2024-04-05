// #include <iostream>
// #include <string>
#include "Zombie.hpp"

int main() {
    std::cout << "Time to create a horde of Zombies!" << std::endl;

    // Appel de la fonction zombieHorde pour créer un tableau de zombies
    int N = 5; // Nombre de zombies à créer
    std::string name = "HordeBros"; // Nom pour tous les zombies
    Zombie* horde = zombieHorde(N, name);

    // Appel de la méthode announce() pour chaque zombie dans la horde
    std::cout << "Zombie Horde Announcements:" << std::endl;
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    // Libération de la mémoire allouée pour la horde de zombies
    delete[] horde;

    return (0);
}