#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Bienvenue dans votre repertoire telephonique !" << std::endl;
    while (true)
    {
        std::cout << "Entrez une commande (ADD, SEARCH ou EXIT): ";
        std::cin >> command;
        if (command == "ADD")
            phoneBook.add();
        else if (command == "SEARCH")
            phoneBook.search();
        else if (command == "EXIT")
            break;
    }
    return 0;
}