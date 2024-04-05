#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

HumanB::~HumanB(){}

//on recupere notre argument par reference puis on le place dans un pointeur
//l' interet est de ne pas avoir a creer de copie de weapon 
//tout en assignant l' adresse de weapon(param) a *_weapon(var membre)
void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack() const
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " can't attack without weapon !!" << std::endl;
}