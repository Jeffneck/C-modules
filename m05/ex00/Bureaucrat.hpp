#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
    private :
        std::string const   _name;
        unsigned int        _grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string const name, unsigned int grade);
        Bureaucrat(Bureaucrat const &to_copy);
        virtual ~Bureaucrat();

        Bureaucrat	&operator=( Bureaucrat& a );

        std::string const	getName() const;
        unsigned int		getGrade() const;
		void				setGrade(unsigned int new_grade);
        void				decrementGrade();
        void				incrementGrade();

		//Exceptions specifiques a notre classe
        class GradeTooHighException : public std::exception
        {
                public :
                    const char  *what() const throw(){
            			return "Grade too high";
        			};
        };
        class GradeTooLowException : public std::exception
        {
                public :
                    const char  *what() const throw(){
            			return "Grade too low";
        			};
        };
};

std::ostream    &operator<<( std::ostream &flux, const Bureaucrat &bureaucrat );

#endif