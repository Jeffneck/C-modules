#pragma once
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& other);
		~Ice();

		AMateria*	clone() const;
		void		use(ICharacter& target) const;
};