#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(Brain const& to_copy)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = to_copy; //utiliser la surcharge '='
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

//surcharges
Brain&  Brain::operator=(Brain const &other)
{
    if (this == &other)
        return(*this);
    this->setIdeas(other._ideas);
    return(*this);
}

void    Brain::setIdeas(const std::string (&nIdeas)[100])
{
    for(int i = 0; i < 100 ; i++)
        _ideas[i] = nIdeas[i];
}

void    Brain::setIdea(const unsigned int index, const std::string &nIdea)
{
        if (index < 100)
            _ideas[index] = nIdea;
        else
            std::cerr << "Index hors de la plage valide. methode setIdea annule" << std::endl;
}

std::string const*    Brain::getIdeas() const
{
    return(_ideas);
}
