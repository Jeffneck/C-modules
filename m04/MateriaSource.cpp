#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learnedMateria({0,0,0,0}){}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	if (this != &other)
		*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
 	if (this != &other)
		return (*this);

	this->delLearnedMaterias();
	for (int i = 0; i < 4; i++)
	{
		if (other._learnedMateria[i])
			_learnedMateria[i] = other._learnedMateria[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	this->delLearnedMaterias();
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_learnedMateria[i])
			{
				this->_learnedMateria[i] = m;
				std::cout << "The recipe to create " << m->getType() <<  " has been learned in MateriaSource !\n";
				return;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type)
		{
			std::cout << "New Materia " << type <<  " has been created by MateriaSource !\n";
			return _learnedMateria[i]->clone();
		}
	}
	return (NULL);
}
void MateriaSource::delLearnedMaterias()
{
	for(int i = 0; i < 4 ; i++)
	{
		if (_learnedMateria[i])
			delete (_learnedMateria[i]);
		_learnedMateria[i] = NULL;
	}
	// std::cout << "All Materias learned by Materia Source have been deleted ! " << std::endl;
}

