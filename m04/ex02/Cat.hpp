#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
 
class Cat : public AAnimal
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