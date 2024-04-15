#include "ScavTrap.hpp"

/*
On appelle le constructeur de la classe parente dans la liste d' init
Cela s'appelle une "initialisation par délégation de constructeur" 
(constructor delegation) et c'est une fonctionnalité du langage C++. 
Elle permet à un constructeur de rediriger son initialisation à un autre constructeur de la même classe ou d'une classe de base.
*/
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

/*La raison pour laquelle cela fonctionne est que ScavTrap est une classe dérivée de ClapTrap. 
Lorsque vous appelez ClapTrap(copy) dans la liste d'initialisation, vous invoquez effectivement 
le constructeur de copie de la classe de base ClapTrap avec un objet de type ScavTrap&. 
Cela est autorisé car un objet de la classe dérivée ScavTrap peut toujours être traité comme un objet de sa classe de base ClapTrap 
(c'est ce qu'on appelle le "slicing").

Cependant, gardez à l'esprit que cela ne copie que la partie de ScavTrap correspondant à ClapTrap. 
Si ScavTrap possède des membres supplémentaires qui ne sont pas présents dans ClapTrap, 
ceux-ci ne seront pas copiés lors de l'appel au constructeur de copie de ClapTrap. Si vous voulez une copie complète de l'objet ScavTrap, vous devrez également implémenter un constructeur de copie spécifique pour ScavTrap qui prend en compte tous ses membres.*/

/* Plus Generalement : 
Dans une relation d'héritage, une classe dérivée peut être traitée comme sa classe de base. 
Cela signifie que vous pouvez utiliser un objet de la classe dérivée là où un objet de la classe de base est attendu. 
Lorsque vous appelez un constructeur de la classe de base avec un objet de la classe dérivée en tant qu'argument, 
le compilateur utilise une conversion implicite pour traiter l'objet de la classe dérivée comme un objet de la classe de base.

Cependant, il est important de noter que cette conversion ne copie que les membres de la classe de base, 
pas les membres supplémentaires de la classe dérivée. 
Si vous avez besoin de copier l'objet de la classe dérivée dans son intégralité, 
vous devrez implémenter un constructeur de copie spécifique pour la classe dérivée qui prend en compte tous ses membres.
*/

ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap " << to_copy._name << " copied" << std::endl;
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

///////////////