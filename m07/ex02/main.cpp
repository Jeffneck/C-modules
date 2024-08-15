#include "Array.hpp"

int main() {
    try {
        Array<int> arr1(5);
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            arr1[i] = i * 10;
        }

        Array<int> arr2 = arr1; // Test du constructeur de copie
        arr2[0] = 100; // Modifie la copie

        std::cout << "arr1[0]: " << arr1[0] << std::endl; // Devrait être 0
        std::cout << "arr2[0]: " << arr2[0] << std::endl; // Devrait être 100

        Array<int> arr3(10);
        arr3 = arr1; // Test de l'opérateur d'assignation
        std::cout << "arr3[0]: " << arr3[0] << std::endl; // Devrait être 0

        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test de l'accès hors limites
        std::cout << arr1[10] << std::endl; // Devrait lancer une exception
    } 
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

