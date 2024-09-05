#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>


/*
Utilite du mot cle typename
	*1*Déclaration de type générique : typename est utilisé pour indiquer que quelque chose est un type dans la définition d'un template.
	*2*Clarification du type dépendant : Lorsqu'un type dépend d'un autre paramètre de template, typename est nécessaire pour indiquer explicitement qu'il s'agit d'un type.
	*3*Éviter l'ambiguïté : Il aide à résoudre les ambiguïtés dans les expressions où le compilateur pourrait confondre un type et une autre entité (comme une fonction ou un membre).
*/


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end()) //si .find() retourne l'iterateur .end() c' est que value n' a pas ete trouvee 
		throw(std::exception());
	return(it);
}


#endif