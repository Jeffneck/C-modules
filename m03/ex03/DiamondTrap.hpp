// #ifndef DIAMONDTRAP_HPP
// #define DIAMONDTRAP_HPP

// #include "ClapTrap.hpp"
// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

// class	DiamondTrap : public FragTrap, public ScavTrap
// {
// 	public :
// 		DiamondTrap();
// 		DiamondTrap(std::string& name);
// 		DiamondTrap(const DiamondTrap& to_copy);
// 		~DiamondTrap();

// 		DiamondTrap &operator=(const DiamondTrap& other);

// 		void	displayStatus()	const;
// 		void	attack(const std::string& target);
// };

// #endif


// Header-protection
#pragma once

// Includes
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// classes

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
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
	// Getter

	// Setter

};