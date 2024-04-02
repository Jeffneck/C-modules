#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

void    PhoneBook::add()
{
    contactList[nbContacts % 8].addContact();
    nbContacts++;
}

void    PhoneBook::search() const
{
    PhoneBook::displayHeaders();
    for (int i = 0; i <= nbContacts; i++)
        contactList[i].displayContact(i);
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