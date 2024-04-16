#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Clappy_clap_trap")
{
	std::cout << "DiamondTrap " << _name << " builded " << std::endl;
	_name = "clappy";
	_hitPts = FragTrap::_hitPts;
	_energyPts = ScavTrap::_energyPts;
	_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy): ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy)
{
	std::cout << "DiamondTrap " << to_copy._name << " copied" << std::endl;
	*this = to_copy;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	std::cout << "DiamondTrap " << name << " builded " << std::endl;
	_name = name;
	_hitPts = FragTrap::_hitPts; //normalement == 100
	_energyPts = ClapTrap::_energyPts; //normalement == 50
	_attackDmg = FragTrap::_attackDmg; //normalement == 30
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	_name = src._name + "_clap_trap";
	_hitPts = src._hitPts;
	_energyPts = src._energyPts;
	_attackDmg = src._attackDmg;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << _name <<
	" and i herited from the ClapTrap named " << ClapTrap::_name << "." <<
	std::endl;
}

void	DiamondTrap::displayStatus()		const
{
	std::cout << "DiamondTrap named = " << _name << ", hit points = " << _hitPts  << ", energy points = " << _energyPts << ", attack damage = " << _attackDmg << std::endl;
	std::cout << "TEST!!!!!!!!!!! " << _name << ", hit points = " << FragTrap::_hitPts  << ", energy points = " << ScavTrap::_energyPts << ", attack damage = " << FragTrap::_attackDmg << std::endl;
}