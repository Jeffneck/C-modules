#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
class AMateria;
class Character
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
};

std::ostream& operator<<(std::ostream& os, Character& toDisplay);

#endif