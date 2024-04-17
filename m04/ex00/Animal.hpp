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
		Animal(Animal &to_copy);
		virtual ~Animal();

		Animal& operator=(Animal& other);
        
		std::string	getType() const;
		virtual void	    makeSound() const;
};

#endif