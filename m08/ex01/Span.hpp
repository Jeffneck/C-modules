#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

/*
	std::array est une version statique de std::vector, où la taille du tableau est définie à la compilation. 
	Si la taille maximale de votre Span est connue à l'avance et n'a pas besoin d'être dynamique, 
	c'est une alternative légère.
*/

/*
	Templates de type : template<typename T> ou template<class T> 
	vous permet de définir des classes ou des fonctions génériques où le type T est spécifié à la compilation.

	Templates de valeur : template<std::size_t N> ou tout autre type numérique (int, char, etc.) 
	vous permet de définir des classes ou des fonctions qui dépendent d'une valeur constante, connue à la compilation.

	Avantages : L'utilisation de templates pour des valeurs permet d'écrire du code générique et réutilisable 
	qui reste performant, car toutes les décisions sur les types et les valeurs sont prises à la compilation. 
	Cela conduit souvent à des optimisations comme l'inlining ou l'élimination de branches de code inutilisées.
*/


class Span
{
	private :
		unsigned int		_maxSize;
		std::vector<int>	_iVector;

	public:
	Span( unsigned int max_size );
	Span( const Span &other );
	~Span();
	Span	&operator=( const Span& a );

	void				addNumber(const int &nb);
	const unsigned int	&shortestSpan( void ) const;
	const unsigned int	&longestSpan( void ) const;
	std::vector<int>	getIntVector( void ) const;

	// template <typename Iterator>
	// void	addRangeNumber(Iterator begin, Iterator end)
	// {
	// 	if (m_int_vector.size() + std::distance(begin, end) > _maxSize)
	// 		throw Span::MaxSizeExeption();
	// 	m_int_vector.insert(m_int_vector.end(), begin, end);
	// 	for (size_t i = 0; i < m_int_vector.size(); i++)
	// 		std::cout << m_int_vector[i] << std::endl;
	// }

	class MaxSizeExeption: public std::exception {
		public:
			const char *what() const throw();
	};

	class IntervalExeption: public std::exception {
		public:
			const char *what() const throw();
	};

};

std::ostream 	&operator<<( std::ostream &flux, const Span &span );
