/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/23 18:15:52 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	static unsigned int nb_call = 0;
	if (nb_call > 20)
		nb_call = 0;
	nb_call++;

	srand((unsigned) time(NULL) * nb_call);
	int					rand_value = std::rand() % 3;

	switch (rand_value)
	{
		case 0:
			std::cout << "A is generated :" << std::endl;
			return (new A);
			break ;
		case 1:
			std::cout << "B is generated :" << std::endl;
			return (new B);
			break ;	
		default :
			std::cout << "C is generated :" << std::endl;
			return (new C);
			break ;
	}
}

void	identify(Base *p)
{
	if (A *a = dynamic_cast<A*>( p ))
		std::cout << "A";
	else if (B *b = dynamic_cast<B*>( p ))
		std::cout << "B";
	else if (C *b = dynamic_cast<C*>( p ))
		std::cout << "C";
}

void	identify(Base& p)
{
	try 
    {
		A &a = dynamic_cast<A&>( p );
        (void)a;
		std::cout << "A"; 
    } 
    catch ( const std::exception & ) {}
	try 
    {
		B &b = dynamic_cast<B&>( p );
		(void)b;
        std::cout << "B"; 
    } 
    catch ( const std::exception & ) {}
	try 
    {
		C &c = dynamic_cast<C&>( p );
		(void)c;
        std::cout << "C"; 
    } 
    catch ( const std::exception & ) {}
}

int	main( void )
{
	for (int i = 0; i < 10; i++)
	{
		Base	*gen_class = generate();
		std::cout << "find class type by pointer => ";
		identify(gen_class);
		std::cout << "\tfind class type by reference => ";
		identify(*gen_class);
		delete gen_class;
		std::cout << "\n" << std::endl;;
	}
	return (0);
}
