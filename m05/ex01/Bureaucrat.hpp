#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private :
        std::string const   _name;
        unsigned int        _grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string const name, unsigned int grade);
        Bureaucrat(Bureaucrat const &to_copy);
        ~Bureaucrat();

        Bureaucrat	&operator=( const Bureaucrat& a );

        void                signForm(Form &form)   const;
        void                announce() const;
        std::string const	getName() const;
        unsigned int		getGrade() const;
		void				setGrade(unsigned int new_grade);
        void				decrementGrade();
        void				incrementGrade();

		//Exceptions specifiques a notre classe
        class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};
};

std::ostream    &operator<<( std::ostream &os, const Bureaucrat &to_display );

#endif