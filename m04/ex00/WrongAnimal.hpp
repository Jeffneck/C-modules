#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
 
class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string &type);
		WrongAnimal(WrongAnimal &to_copy);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(WrongAnimal& other);
        
		std::string	getType() const;
		void	    makeSound() const;
};

#endif