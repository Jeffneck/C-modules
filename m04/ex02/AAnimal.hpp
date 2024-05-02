#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(std::string &type);
		AAnimal(AAnimal const&to_copy);
		virtual ~AAnimal();

		AAnimal& operator=(AAnimal const& other);
        
		std::string			getType() const;
		virtual void	    makeSound() const = 0;
};

#endif



/*
Pour déclarer une classe comme étant une classe abstraite en C++, 
vous devez inclure au moins une fonction virtuelle pure dans la classe. 
Une fonction virtuelle pure est une fonction virtuelle 
qui n'a pas de définition dans la classe de base et est marquée avec = 0 à la fin de sa déclaration.
Cela signifie que les classes dérivées doivent fournir une implémentation pour cette fonction pour être considérées comme des classes complètes.
*/