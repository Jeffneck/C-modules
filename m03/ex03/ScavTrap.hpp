#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//si on ne met pas virtual, il y aura 2 instances de claptrap crees au lieu d'1 seule commune a fragtrap et scavtrap
class	ScavTrap : virtual public ClapTrap 
{
	protected : 
	unsigned int _scav_enregyPts;

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