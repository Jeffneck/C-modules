#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
 
class Dog : public AAnimal
{
	public :
		Dog();
		Dog(Dog const& to_copy);
		~Dog();
		Dog&  operator=(Dog const& other);

		void		makeSound() const;
		Brain const *getBrain() const;
		void		printIdeas() const;
		void		setIdeas(const std::string (&nIdeas)[100]);
		void		setIdea(const unsigned int index, const std::string &nIdea);

	
	private :
		Brain *_brain;
};

#endif