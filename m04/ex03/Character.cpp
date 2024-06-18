#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name), _inventory({0,0,0,0})
{
	std::cout << _name << " Character Constructor\n";
}

Character::Character(Character& toCopy)
{
	if (this != &other)
		return (*this);
	*this = toCopy;
}

//deep_copy = (recreate new materia with materia.clone())
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
	this->delInventory();
	std::cout << "Character Destructor" << std::endl;
}


std::string const & Character::getName() const
{
	return(_name);
}

/* 
Add Materia in order
Do nothing if we try to equip thus we already have 4 Materia

*/
void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				std::cout << "Character " << _name << " equipped with " << m->getType() << std::endl;
				return;
			}
		}
		std::cout << "Character " << _name << " can't equip " << m->getType() << std::endl;
	}
}

/* 
Don't del unequiped Materia, save it's adress to del it in the Character destructor 
Do nothing if we try to unequip inexisting Materia (keep the address to further dest)

*/
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		{
			std::cout << "Character " << _name << " unequipped " << _inventory[idx]->getType() << std::endl;
			_inventory[idx] = NULL;
		}
	else
			std::cout << "Character " << _name << " can't unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << "Character " << _name << " uses " << _inventory[idx]->getType() << std::endl;
		_inventory[idx]->use(target);
	}
	else
		std::cout << "Character " << _name << " can't use" << std::endl;
}

void Character::delInventory()
{
	for(int i = 0; i < 4; i++)
	{
		if(_inventory[i])
			delete _inventory[i];
	}
}