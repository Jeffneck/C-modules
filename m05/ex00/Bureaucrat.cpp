#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade)
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &to_copy)
{

}

Bureaucrat::~Bureaucrat()
{

}

// Methods -------------------------------

std::string     Bureaucrat::getName()
{
    return(_name);
}
unsigned int    Bureaucrat::getGrade()
{
    return(_grade);
}
void            Bureaucrat::decrementGrade()
{

}
void            Bureaucrat::incrementGrade()
{

}