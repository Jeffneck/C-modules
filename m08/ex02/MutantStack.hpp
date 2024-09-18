#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP


#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>
#include <deque>


template<typename T>


class MutantStack: public std::stack<T, std::deque<T> >
{

	public:
		typedef std::stack<T, std::deque<T> > stackClass; //alias pour la classe stack
		typedef typename std::deque<T>::iterator iterator; //alias pour l'iterator (pratique pour appeler l' iterateur depuis l' exterieur (attention, le typedef doit etre public))
		
		MutantStack() : stackClass(){};
		MutantStack(const MutantStack<T>& other) : stackClass(other) {};
		~MutantStack(){};

		MutantStack<T>&		operator=(const MutantStack<T>& other) {
        if (this != &other) { 
            stackClass::operator=(other); // Appel de l'opérateur d'affectation de la classe de base
        }
        return *this;
    }

	//on accede a la variable c qui est en fait le container std::deque qui est contenu dans la stack et qui du coup contient en son sein les methodes begin() et end()
	iterator begin(){return this->c.begin();};
	iterator end(){return this->c.end();};
};



#endif