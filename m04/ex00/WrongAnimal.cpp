#include "WrongAnimal.hpp"

//Constructors
WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
}
WrongAnimal::WrongAnimal(std::string &type) : _type(type)
{
    std::cout << "WrongAnimal std::string constructor called." << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal &to_copy) : _type(to_copy._type)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

//Operators
WrongAnimal&     WrongAnimal::operator=(WrongAnimal& other)
{
    if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
    return (_type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << " *Some unknown WrongAnimal sound* " << std::endl;
}
