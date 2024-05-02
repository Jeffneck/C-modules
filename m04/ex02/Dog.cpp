#include "Dog.hpp"

//Constructors
Dog::Dog() : AAnimal()
{
    _type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
    _brain = new Brain();
}
Dog::Dog(Dog const& to_copy) : AAnimal(to_copy)
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = to_copy;
}
Dog::~Dog()
{
    delete(_brain);
    std::cout << "Dog destructor called." << std::endl;
}

//operators
Dog&  Dog::operator=(Dog const& other)
{
    if (this == &other)
        return(*this);
    //deep copy of the brain by using new alloc
    _brain = new Brain(*(other.getBrain()));
    return(*this);
}

// modified member
void    Dog::makeSound() const
{
    std::cout << " *RrrrrWoafWOUF* " << std::endl;
}

Brain const *Dog::getBrain() const
{
    return (_brain);
}

void    Dog::printIdeas() const
{
    std::string const *dogIdeas = _brain->getIdeas();
    for(int i = 0; i < 100; i++)
    {
        if (dogIdeas[i][0] == '\0')
            break;
        std::cout << "Idea : " << dogIdeas[i] << std::endl;
    }
}

void    Dog::setIdeas(const std::string (&nIdeas)[100])
{
    _brain->setIdeas(nIdeas);
}

void    Dog::setIdea(const unsigned int index, const std::string &nIdea)
{
    _brain->setIdea(index, nIdea);
}

