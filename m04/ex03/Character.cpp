#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name), _inventory({0,0,0,0})
{
	// std::cout << this->_name << " Default constructor Character\n";
}

Character::Character(Character& toCopy)
{
	if (this != &other)
		return (*this);
	*this = toCopy;
}

Character& Character::operator=(Character& other)
{
	if (this != &other)
		return (*this);
	
	this->delInventory();
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	//del remaining materia
}


std::string const & Character::getName() const
{

}

/* 
Add Materia in order
Do nothing if we try to equip thus we already have 4 Materia

*/
void Character::equip(AMateria* m)
{

}

/* 
Don't del unequiped Materia, save it's adress to del it in the Character destructor 
Do nothing if we try to unequip inexisting Materia (keep the address to further dest)

*/
void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
	//do i need to do another thing ?
	_inventory[idx].AMateria::use(target);
}

void Character::delInventory()
{
	for(int i = 0; i < 4; i++)
	{
		if(_inventory[i])
			delete _inventory[i];
	}
}