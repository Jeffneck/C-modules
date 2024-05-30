#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
    public :
    Bureaucrat();
    Bureaucrat(std::string const name, unsigned int grade);
    Bureaucrat(Bureaucrat const &to_copy);
    virtual ~Bureaucrat(); // virtual pas necess pour le 1er ex

    Bureaucrat	&operator=( Bureaucrat& a );

    std::string     getName() const;
    unsigned int    getGrade() const;
    void            decrementGrade();
    void            incrementGrade();

    private :
        std::string const   _name;
        unsigned int        _grade;

};

std::ostream operator<<(Bureaucrat &obj, std::ostream os); // verif

#endif