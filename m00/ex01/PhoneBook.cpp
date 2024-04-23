#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : nbContacts(0){}

void    PhoneBook::add()
{
    if (nbContacts == 8)
        nbContacts = 0;
    contactList[nbContacts].addContact();
    nbContacts++;
}

void    PhoneBook::search() const
{
    PhoneBook::displayHeaders();
    for (int i = 0; i < 8; i++)
        contactList[i].displayContact(i);

    std::cout << std::endl;
    int nb;
    std::cout << "Veuillez entrer l'index d'un contact : ";
    if (std::cin >> nb && nb < 8)
        contactList[nb].displayContactGlobal(nb);
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur : Entrée invalide. Affichage annule." << std::endl;
    }
}

void    PhoneBook::displayHeaders() const
{
    std::cout 
    << std::setw(10) << "INDEX" << "|"
    << std::setw(10) << "FIRST NAME" << "|" 
    << std::setw(10) << "LAST NAME" << "|" 
    << std::setw(10) << "NICKNAME" 
    << std::endl;
}