#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name )
{
    Zombie  *zomBoyss = new Zombie[N];

    for (int i = 0; i < N; i++)
        zomBoyss[i].setName(name);
    return(zomBoyss);
}