#include "Cat.hpp"

//Constructors
Cat::Cat() : AAnimal()
{
    _type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
    _brain = new Brain();
}
Cat::Cat(Cat const& to_copy) : AAnimal(to_copy)
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = to_copy;
}
Cat::~Cat()
{
    delete(_brain);
    std::cout << "Cat destructor called." << std::endl;
}

//operators
Cat&  Cat::operator=(Cat const& other)
{
    if (this == &other)
        return(*this);
    //deep copy of the brain by using new alloc
    _brain = new Brain(*(other.getBrain()));
    return(*this);
}

// modified member
void    Cat::makeSound() const
{
    std::cout << " *trlluuuMeow* " << std::endl;
}

Brain const *Cat::getBrain() const
{
    return (_brain);
}

void    Cat::printIdeas() const
{
    std::string const *dogIdeas = _brain->getIdeas();
    for(int i = 0; i < 100; i++)
    {
        if (dogIdeas[i][0] == '\0')
            break;
        std::cout << "Idea : " << dogIdeas[i] << std::endl;
    }
}

void    Cat::setIdeas(const std::string (&nIdeas)[100])
{
    _brain->setIdeas(nIdeas);
}

void    Cat::setIdea(const unsigned int index, const std::string &nIdea)
{
    _brain->setIdea(index, nIdea);
}

