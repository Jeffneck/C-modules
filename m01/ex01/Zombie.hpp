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



    




#endif //ZOMBIE_HPP