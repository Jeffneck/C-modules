#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


//on reference claptrap comme classe mere de maniere virtuelle a cause du dilemme du diamant
class	FragTrap : virtual public ClapTrap
{
	public :
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& to_copy);
		~FragTrap();

		FragTrap &operator=(const FragTrap& other);

		void	displayStatus()	const;
		void	attack(const std::string& target);
		void	highFivesGuys();
};

#endif