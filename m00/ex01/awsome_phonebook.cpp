#include "awsome_phonebook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Bienvenue dans votre repertoire telephonique !" << std::endl;

    while (true) {
        std::cout << "Entrez une commande";
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

// int main() {
//     PhoneBook phoneBook;
//     std::string command;

//     std::cout << "Bienvenue dans votre repertoire telephonique !" << std::endl;

//     while (true) {
//         std::cout << "Entrez une commande (ADD, SEARCH ou EXIT) : ";
//         std::cin >> command;

//         if (command == "ADD") {
//             phoneBook.addContact();
//         } else if (command == "SEARCH") {
//             phoneBook.searchContact();
//         } else if (command == "EXIT") {
//             std::cout << "Au revoir !" << std::endl;
//             break;
//         } else {
//             std::cout << "Commande inconnue. Veuillez reessayer." << std::endl;
//         }
//     }

//     return 0;
// }