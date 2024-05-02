#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
 
class WrongCat : public WrongAnimal
{

	public:
		WrongCat();
		WrongCat(WrongCat& to_copy);
		~WrongCat();

		void	    makeSound() const;
};

#endif