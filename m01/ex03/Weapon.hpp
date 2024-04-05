#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>
class   Weapon
{
    public :
        const std::string &getType() const;
        void        setType(const std::string newType);
        Weapon(const std::string type);
        Weapon();
        ~Weapon();

    private :
        std::string _type;
};

#endif