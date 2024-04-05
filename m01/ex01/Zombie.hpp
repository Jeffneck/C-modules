#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        void announce ( void ) const;
        Zombie();
        Zombie(std::string name);
        ~Zombie();
};


Zombie  *zombieHorde( int N, std::string name );
Zombie  *newZombie( std::string name );
void    randomChump( std::string name);

    




#endif //ZOMBIE_HPP