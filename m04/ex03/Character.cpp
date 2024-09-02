#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name)
{
	// std::cout << _name << " Character Constructor\n";
	for (int i = 0; i < 4; ++i) 
        _inventory[i] = NULL;
}

Character::Character(Character& toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
}

/*deep_copy = (recreate new materia with materia.clone())*/
Character& Character::operator=(Character& other)
{
	if (this != &other)
		return (*this);

	_name = other._name;
	this->delInventory();
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	this->delInventory();
	// std::cout << "Character Destructor" << std::endl;
}


std::string const & Character::getName() const
{
	return(_name);
}


void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				// std::cout << "Character : " << _name << " add materia " << m->getType() << " into his inventory " << std::endl;
				return;
			}
		}
		// std::cout << "Character " << _name << " can't add the " << m->getType() << "materia into his inventory " << std::endl;
	}
}

/* 
Don't del unequiped Materia, save it's adress to del it in the Character destructor 
Do nothing if we try to unequip inexisting Materia (keep the address to delete it later)
*/
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		{
			std::cout << "Character " << _name << " unequipped " << _inventory[idx]->getType() << std::endl;
			_inventory[idx] = NULL;
		}
	else
			std::cout << "Character " << _name << " couldn't unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

void Character::delInventory()
{
	for(int i = 0; i < 4; i++)
	{
		if(_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
}