#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
_name("Clappy"), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "ClapTrap " << _name << " builded " << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : 
_name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "ClapTrap " << _name << " builded " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy) : 
_name(to_copy._name), _hitPts(to_copy._hitPts), _energyPts(to_copy._energyPts), _attackDmg(to_copy._attackDmg)
{
	std::cout << "ClapTrap " << to_copy._name << " copied" << std::endl;
} 

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructed" << std::endl;
}

//operators

ClapTrap&		ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hitPts = other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
	return(*this);
}


// methodes
int		ClapTrap::isDisabled(void)	const
{
	if(_energyPts <= 0)
	{
		std::cout << "Trap has no energy left so he can't attack/repair !" << std::endl;
		return (1);
	}
	else if(_hitPts <= 0)
	{
		std::cout << "Trap has no hit points left so he can't attack/repair !" << std::endl;
		return (1);
	}
	return (0);
}


void	ClapTrap::attack(const std::string& target)
{
	if (isDisabled())
		return;
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDmg << " points of damage!" <<std::endl;
	_energyPts--;
}		

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPts == 0) {
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage but was already disabled" << std::endl;
} else if (amount >= _hitPts) {
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and is disabled" << std::endl;
    _hitPts = 0;
} else {
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    _hitPts -= amount;
}
	

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isDisabled())
		return;
	std::cout << "ClapTrap " << _name << " repaired, he is now " << amount << " points healthier !" <<std::endl;
	_hitPts += amount;
	_energyPts--;
}



//Getters
std::string	ClapTrap::get_name()		const
{
	return(_name);
}

unsigned int			ClapTrap::get_hitPts()	const
{
	return(_hitPts);
}

unsigned int			ClapTrap::get_energyPts()	const
{
	return(_energyPts);
}

unsigned int			ClapTrap::get_attackDmg()	const
{
	return(_attackDmg);
}

void	ClapTrap::displayStatus()		const
{
	std::cout << "ClapTrap named = " << _name << ", hit points = " << _hitPts  << ", energy points = " << _energyPts << ", attack damage = " << _attackDmg << std::endl;
}