#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


# define BLUE "\033[1m\033[4m\033[34m"
# define RESET "\033[0m"
int main()
{
	{
		std::cout << BLUE << "\nSUBJECT MAIN\n" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << BLUE << "\nADDED MAIN\n" << RESET << std::endl;
		std::cout << BLUE << "\nCreating a spell book.\n" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		
		std::cout << BLUE << "\nCreating a character.\n" << RESET << std::endl;
		ICharacter* noctis = new Character("Noct");
		ICharacter* pablo = new Character("Pablo");

		std::cout << BLUE << "\nAdding the spell to the book.\n" << RESET << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << BLUE << "\nTranscription of spell into spell parchment.\n" << RESET << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("ice");
		noctis->equip(tmp);
		tmp = src->createMateria("cure");
		noctis->equip(tmp);

		std::cout << BLUE << "\nNoct uses spells on Pablo\n" << RESET << std::endl;
		
		noctis->use(0, *pablo);
		noctis->use(1, *pablo);

		std::cout << BLUE << "\nPablo takes revenge on noct\n" << RESET << std::endl;
		tmp = src->createMateria("ice");
		pablo->equip(tmp);
		pablo->use(0, *noctis);

		std::cout << BLUE << "\nShiva changes its spell\n" << RESET << std::endl;
		Character *shiva = new Character("shiva");
		AMateria* toDel = src->createMateria("cure");
		AMateria* toKeep = src->createMateria("ice");

		shiva->equip(toDel);
		shiva->use(0, *pablo);

		shiva->equip(toKeep);
		shiva->unequip(0);
		shiva->use(0, *pablo); // do nothing
		shiva->use(1, *pablo);
		delete toDel;

		std::cout << BLUE << "\nDestroying instances\n" << RESET << std::endl;
		// std::cout << std::endl;
		delete src;
		delete pablo;
		delete noctis;
		delete shiva;
	}

	return 0;
}



// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }