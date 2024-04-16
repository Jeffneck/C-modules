#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class	ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& to_copy);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap& other);

		void	displayStatus()	const;
		void	attack(const std::string& target);
		void	guardGate();
};

#endif