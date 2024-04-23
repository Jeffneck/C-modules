#include "Dog.hpp"

//Constructors
Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(Dog &to_copy) : Animal(to_copy)
{
    std::cout << "Dog copy constructor called." << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

// modified member
void    Dog::makeSound() const
{
    std::cout << " *RrrrrWoafWOUF* " << std::endl;
}
