#pragma once

#include <string>


class AMateria;
class Character : public ICharacter
{
	private :
		std::string			_name;
		AMateria*			_inventory[4];

	public:
		Character(std::string name);
		Character(Character& copy);
		Character& operator=(Character& other);
		~Character();
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void delInventory();

};

std::ostream& operator<<(std::ostream& os, Character& toDisplay);
