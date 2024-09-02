# include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
}

AMateria::~AMateria(){}

void		use(ICharacter& target)
{
	std::cout << target.getName();
}


AMateria &AMateria::operator=(const AMateria &a)
{
	(void)a;
	return (*this);
}

void		AMateria::use(ICharacter& target) const
{ (void)target;}

std::string const&	AMateria::getType() const
{
	return(_type);
}
