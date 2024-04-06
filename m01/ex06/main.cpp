#include "Harl.hpp"

int setHarlFilter(std::string &level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if(level == levels[i])
            return(i);
    }
    return(-1);
}

int main(int ac, char **av)
{
    
    Harl iAmHarl;

    if (ac == 2)
        iAmHarl.setFilter(av[1]);
    iAmHarl.complainFilter();

    return (0);
}