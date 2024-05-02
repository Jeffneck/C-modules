#include "WrongCat.hpp"

//Constructors
WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat &to_copy) : WrongAnimal(to_copy)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

// modified member
void    WrongCat::makeSound() const
{
    std::cout << " *wrong cat sound* " << std::endl;
}
