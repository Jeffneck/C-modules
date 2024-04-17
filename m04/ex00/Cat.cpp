#include "Cat.hpp"

//Constructors
Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}
Cat::Cat(Cat &to_copy) : Animal(to_copy)
{
    std::cout << "Cat copy constructor called." << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

// modified member
void    Cat::makeSound() const
{
    std::cout << " *trlluuuMeow* " << std::endl;
}
