#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class	ClapTrap
{
	public :
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& to_copy);
		virtual ~ClapTrap();
		virtual void		displayStatus()	const;

		ClapTrap &operator=(const ClapTrap& other);


		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount); 

		std::string	get_name()		const;
		unsigned int			get_hitPts()	const;
		unsigned int			get_energyPts()	const;
		unsigned int			get_attackDmg()	const;


	protected :
		std::string _name;
		unsigned int	_hitPts;
		unsigned int _energyPts;
		unsigned int	_attackDmg;

		int	isDisabled(void)	const;

};



#endif