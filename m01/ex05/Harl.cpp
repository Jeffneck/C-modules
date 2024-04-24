#include "Harl.hpp"

Harl::Harl()
{
    std::cout << GRAY << "[CREATION]:" << RESET
    << "A new messenger came to earth, his name is Harl, let's listen his teachings"
    << std::endl;
    //ler les mots cles aux pointeurs de methodes
    _levelMap[0].level = "DEBUG"; 
    _levelMap[0].func = &Harl::debug;
    _levelMap[1].level = "INFO"; 
    _levelMap[1].func = &Harl::info;
    _levelMap[2].level = "WARNING"; 
    _levelMap[2].func = &Harl::warning;
    _levelMap[3].level = "ERROR"; 
    _levelMap[3].func = &Harl::error;
}

Harl::~Harl()
{
    std::cout << GRAY << "[DESTRUCTION]:" << RESET
    << "We'll miss you Harl, another angel gone too soon..."
    << RESET
    << std::endl;
}

void    Harl::complain( std::string level)
{
    int nbLevels = sizeof(_levelMap) / sizeof(t_levelMap);

    for(int i = 0; i < nbLevels; i++)
    {
        if(level == _levelMap[i].level)
            (this->*(_levelMap[i].func))(); //on derefenrence l'adresse de la methode 
    }
}

void    Harl::debug()
{
    std::cout << MAGENTA << "[DEBUG]\n" << RESET
	<< "I love to get extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
	<< " I just love it!" << std::endl;
}

void    Harl::info()
{
    std::cout << GRAY << "[INFO]\n" << RESET
	<< "I cannot believe adding extra bacon cost more money."
	<< " You don’t put enough! If you did I would not have to ask"
	<< " for it!" << std::endl;
}

void    Harl::warning()
{
	std::cout << YELLOW << "[WARNING]\n" << RESET
	<< "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming here for years and you just started "
	<< "working here last month." << std::endl;
}

void    Harl::error()
{
	std::cout << RED << "[ERROR]\n" << RESET
	<< "This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}