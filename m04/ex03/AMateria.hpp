#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();

		virtual AMateria&	operator=(const AMateria &a);
		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target) const;
};


#endif