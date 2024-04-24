#include "Zombie.hpp"

void    Zombie::announce( void ) const
{
    std::cout 
    << this->name 
    << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie::Zombie()
{
    this->name = "*Unnamed Z*";
    std::cout
    << "a fellow Zombie Unnamed"
    << " had been CREATED"
    << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout
    << "a fellow Zombie named "
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

