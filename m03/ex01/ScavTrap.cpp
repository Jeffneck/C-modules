#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << _name << " created" << std::endl;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " created" << std::endl;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap " << to_copy._name << " copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructed" << std::endl;
}

//operators

ScavTrap&		ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPts = other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
	return(*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (isDisabled())
		return;
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDmg << " points of damage!" <<std::endl;
	_energyPts--;
}

void	ScavTrap::displayStatus()		const
{
	std::cout << "ScavTrap named = " << _name << ", hit points = " << _hitPts  << ", energy points = " << _energyPts << ", attack damage = " << _attackDmg << std::endl;
}

void	ScavTrap::guardGate( void )
{
		std::cout << "ScavTrap " << _name << " is guarding gate !" << std::endl;
}