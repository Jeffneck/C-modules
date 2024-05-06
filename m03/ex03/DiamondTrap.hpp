#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

// Includes
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// classes

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;//we changed the claptrap name
	public:
	// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);

	// Deconstructors
		virtual ~DiamondTrap();

	// Overloaded Operators
		DiamondTrap &operator=(const DiamondTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void whoAmI(void);
		void displayStatus() const;
};

#endif