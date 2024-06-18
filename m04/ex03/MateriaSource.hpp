#pragma once

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{	
	private :
		AMateria* _learnedMateria[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
		void		delLearnedMaterias();

};