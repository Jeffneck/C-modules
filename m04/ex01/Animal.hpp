#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string &type);
		Animal(Animal const&to_copy);
		virtual ~Animal();

		Animal& operator=(Animal const& other);
        
		std::string			getType() const;
		virtual void	    makeSound() const;
};

#endif