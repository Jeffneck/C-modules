#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() : 
firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){}


void    Contact::addContact(){
    std::cout << "Entrez le prenom : ";
    std::cin >> firstName;
    std::cout << "Entrez le nom de famille : ";
    std::cin >> lastName;
    std::cout << "Entrez le surnom : ";
    std::cin >> nickname;
    std::cout << "Entrez le numero de telephone : ";
    std::cin >> phoneNumber;
    std::cout << "Entrez le secret le plus sombre : ";
    std::cin >> darkestSecret;
}

void    Contact::displayContact(int index) const
{
    std::string firstN = firstName.length() < 10 ? firstName : firstName.substr(0,9) + ".";
    std::string lastN = lastName.length() < 10 ? lastName : lastName.substr(0,9) + ".";
    std::string nickN = nickname.length() < 10 ? nickname : nickname.substr(0,9) + ".";
    
    std::cout 
    << std::setw(10) << index << "|" 
    << std::setw(10) << firstN << "|" 
    << std::setw(10) << lastN << "|" 
    << std::setw(10) << nickN << std::endl;
}

void    Contact::displayContactGlobal(int index) const
{   
    std::cout << "Contact Index : " << index << std::endl; 
    std::cout << "First Name : " << firstName << std::endl; 
    std::cout << "Last Name : " << lastName << std::endl; 
    std::cout << "Nickname : " << nickname << std::endl; 
    std::cout << "PhoneNumber : " << phoneNumber << std::endl; 
    std::cout << "Darkest Secret : " << darkestSecret << std::endl; 
}