#include "Array.hpp"

int main() {
	std::cout << "\n---- TEST ARRAY INT ----" << std::endl;

    try {
        Array<int> arr1(10);
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            arr1[i] = i * 10;
			std::cout << "arr1[" << i << "] : "<< arr1[i] << std::endl;
        }
		
		std::cout << "\n-- Copy constructor :" << std::endl;
        Array<int> arr2 = arr1; // Test du constructeur de copie
        std::cout << "arr1[0]: " << arr1[0] << std::endl; // Devrait être 0
        std::cout << "arr2[0] after copy : " << arr2[0] << std::endl; // Devrait être 0


		std::cout << "\n-- Modif index with [] operator:" << std::endl;
        arr2[0] = 54; // Modifie la copie
        std::cout << "arr2[0] after copy : " << arr2[0] << std::endl; // Devrait être 54


		std::cout << "\n-- Assignement operator :" << std::endl;
        Array<int> arr3(5);
        arr3 = arr1; // Test de l'opérateur d'assignation
        std::cout << "arr1[3]: " << arr1[3] << std::endl; // Devrait être 30
        std::cout << "arr3[3]: " << arr3[3] << std::endl; // Devrait être 30

        std::cout << "arr1 size: " << arr1.size() << std::endl;
        std::cout << "arr3 size: " << arr1.size() << std::endl;



		std::cout << "\n-- Access out of boundaries (exception) :" << std::endl;

        std::cout << arr1[10] << std::endl; // Devrait lancer une exception
    } 
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }



	std::cout << "\n\n\n---- TEST ARRAY CHAR ----" << std::endl;
	try {
        Array<char> arr1(10);
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            arr1[i] = static_cast<char>(i + 'a');
			std::cout << "arr1[" << i << "] : "<< arr1[i] << std::endl;
        }
		std::cout << "\n-- Copy constructor + modif :" << std::endl;

        Array<char> arr2 = arr1; // Test du constructeur de copie
        arr2[0] = 'm'; // Modifie la copie

        std::cout << "arr1[0]: " << arr1[0] << std::endl; // Devrait être a
        std::cout << "arr2[0]: " << arr2[0] << std::endl; // Devrait être m

		std::cout << "\n-- ASSIGNEMENT OPERATOR : --" << std::endl;
        Array<char> arr3(5);
		std::cout << "\n-- BEFORE Assignement :" << std::endl;
        for (unsigned int i = 0; i < arr3.size(); ++i) {
			std::cout << "arr3[" << i << "] : '"<< arr3[i] << "'"<< std::endl;
        }

        arr3 = arr1;
		std::cout << "\n-- AFTER Assignement :" << std::endl;

        for (unsigned int i = 0; i < arr3.size(); ++i) {
			std::cout << "arr3[" << i << "] : '"<< arr3[i] << "'"<< std::endl;
        }

        std::cout << "arr1 size: " << arr1.size() << std::endl;
        std::cout << "arr3 size: " << arr1.size() << std::endl;

    } 
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

