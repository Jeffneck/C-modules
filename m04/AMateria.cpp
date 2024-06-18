# include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(const AMateria &a)
{
	// According to the subject, it's useless to copy the type of the Materia
	// So we have nothing to do here.
	(void)a;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return(_type);
}