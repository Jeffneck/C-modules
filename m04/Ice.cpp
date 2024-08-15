#include "Ice.hpp"

Ice::Ice() : AMateria("cure"){}

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
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}