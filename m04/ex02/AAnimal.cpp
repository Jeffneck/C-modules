#include "AAnimal.hpp"

//Constructors
AAnimal::AAnimal() : _type("")
{
    std::cout << "AAnimal default constructor called." << std::endl;
}
AAnimal::AAnimal(std::string &type) : _type(type)
{
    std::cout << "AAnimal std::string constructor called." << std::endl;
}
AAnimal::AAnimal(AAnimal const& to_copy) : _type(to_copy._type)
{
    std::cout << "AAnimal copy constructor called." << std::endl;
}
AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called." << std::endl;
}

//Operators
AAnimal&     AAnimal::operator=(AAnimal const& other)
{
    if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	AAnimal::getType() const
{
    return (_type);
}
