#include "Animal.hpp"

//Constructors
Animal::Animal() : _type("")
{
    std::cout << "Animal default constructor called." << std::endl;
}
Animal::Animal(std::string &type) : _type(type)
{
    std::cout << "Animal std::string constructor called." << std::endl;
}
Animal::Animal(Animal const& to_copy) : _type(to_copy._type)
{
    std::cout << "Animal copy constructor called." << std::endl;
}
Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

//Operators
Animal&     Animal::operator=(Animal const& other)
{
    if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	Animal::getType() const
{
    return (_type);
}

void    Animal::makeSound() const
{
    std::cout << " *Some unknown Animal sound* " << std::endl;
}
