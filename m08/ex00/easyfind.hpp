#include <iostream>
#include <vector>
#include <algorithm>


/*
	T represente la variable du template
	typename T represente le type de la variable du template
	typename T::iterator represente un element contenu dans le container
*/

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw(std::runtime_error("Exception: Value not found"));
	return(it);
}


