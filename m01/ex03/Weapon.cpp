#include "Weapon.hpp"

Weapon::Weapon() : _type(""){}
Weapon::~Weapon(){}

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string&    Weapon::getType() const
{
    return(this->_type);
}

void            Weapon::setType(std::string newType)
{
    this->_type = newType;
}

