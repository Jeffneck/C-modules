#ifndef ITER_HPP
#define ITER_HPP


template<typename T>
void iter(T *array, size_t size, void(*f)(T const &))
{
	if (!array || !size || !f)
		return;
	for(size_t i = 0; i < size; i++ )
		f(array[i]);
}

template< typename T >
void print( T const & x ) 
{ 
	std::cout << x << std::endl; 
}































































/*Astuce permettant de specialiser le comportement d' une fonction utilisant un template*/

//premierement on initialise la struct avec une value false
template <typename T>
struct is_intType { static const bool value = false; };


template <>//on specialise le template pour detecter quand T est un int
struct is_intType<int> { static const bool value = true; };// si T est un in value devient true

template <typename T>
void power2( T const & x ) 
{
	if(x < 1000 && x > 0 && is_intType<T>::value) 
	{
		std::cout << x << " power2 is = ";
		print(x*x);
	}
}


#endif