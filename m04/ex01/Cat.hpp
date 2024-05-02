#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
 
class Cat : public Animal
{

	public :
		Cat();
		Cat(Cat const& to_copy);
		~Cat();
		Cat&  operator=(Cat const& other);

		void		makeSound() const;
		Brain const *getBrain() const;
		void		printIdeas() const;
		void		setIdeas(const std::string (&nIdeas)[100]);
		void		setIdea(const unsigned int index, const std::string &nIdea);

	
	private :
		Brain *_brain;
};

#endif