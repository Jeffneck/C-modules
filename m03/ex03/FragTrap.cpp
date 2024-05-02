#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << _name << " created" << std::endl;
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " created" << std::endl;
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap " << to_copy._name << " copied" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructed" << std::endl;
}

//operators
FragTrap&		FragTrap::operator=(const FragTrap& other)
{
	_name = other._name;
	_hitPts = other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
	return(*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (isDisabled())
		return;
	std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDmg << " points of damage!" <<std::endl;
	_energyPts--;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << _name << " is giving a high Five !" << std::endl;
}


void	FragTrap::displayStatus()		const
{
	std::cout << "FragTrap named = " << _name << ", hit points = " << _hitPts  << ", energy points = " << _energyPts << ", attack damage = " << _attackDmg << std::endl;
}
