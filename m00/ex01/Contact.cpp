#include "Contact.hpp"

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
    //ajouter : Si le texte dépasse la largeur de la colonne, 
    //il faut le tronquer et remplacer le dernier caractère affiché par un point (’.’).
    std::cout 
    << std::setw(10) << index << "|" // comment afficher un int
    << std::setw(10) << firstName << "|" 
    << std::setw(10) << lastName << "|" 
    << std::setw(10) << nickname 
    << std::endl;
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

void    Contact::displayContact(int index) const
{
    //ajouter : Si le texte dépasse la largeur de la colonne, 
    //il faut le tronquer et remplacer le dernier caractère affiché par un point (’.’).
    std::cout << std::setw(10) << index << "|"; // comment afficher un int
    
    if(firstName.length() < 10)
        std::cout << std::setw(10) << firstName << "|";
    else
        std::cout << std::setw(10) << firstName.substr(0, 9) << "." << "|"
    if(firstName.length() < 10)
        std::cout << std::setw(10) << firstName << "|";
    else
        std::cout << std::setw(10) << firstName.substr(0, 9) << "." << "|"

    if(firstName.length() < 10)
        std::cout << std::setw(10) << firstName << "|";
    else
        std::cout << std::setw(10) << firstName.substr(0, 9) << "." << "|"
    if(firstName.length() < 10)
        std::cout << std::setw(10) << firstName << std::endl;
    else
        std::cout << std::setw(10) << firstName.substr(0, 9) << "." << std::endl;
    << std::setw(10) << lastName << "|" 
    << std::setw(10) << nickname 
    << std::endl;
}