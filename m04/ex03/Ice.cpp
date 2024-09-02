#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice& copy): AMateria((const AMateria&)copy) {}

Ice::~Ice(){}

Ice& Ice::operator=(const Ice& other)
{
	this->AMateria::operator=(other);
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) const
{
	AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}