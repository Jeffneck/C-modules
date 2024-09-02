#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure& copy): AMateria((const AMateria&)copy) {}

Cure& Cure::operator=(const Cure& other)
{
	this->AMateria::operator=(other);
	return *this;
}

Cure::~Cure(){}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) const
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}