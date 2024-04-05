#include "Zombie.hpp"

void    Zombie::announce( void ) const
{
    std::cout 
    << this->name 
    << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout
    << "a FELLOW Zombie named "
    << this->name 
    << " had been CREATED"
    << std::endl;
}

Zombie::~Zombie()
{
    std::cout
    << "a brave Zombie named "
    << this->name 
    << " had been savagely killed by a dev ...RIP... "
    << std::endl;
}

