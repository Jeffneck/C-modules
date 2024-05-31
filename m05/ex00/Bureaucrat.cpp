#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unamed"), _grade(150)
{
    std::cout << "Default constructor called -" 
    << " Brureaucrat : " << _name << " Grade : " << _grade 
    << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): _name(name)
{
    this->setGrade(grade);
    std::cout << "Specific constructor called -" 
    << " Brureaucrat : " << _name << " Grade : " << _grade 
    << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &to_copy) : _name(to_copy.getName())
{
    this->setGrade(to_copy.getGrade());
    std::cout << "Copy constructor called -" 
    << " Brureaucrat : " << _name << " Grade : " << _grade 
    << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called -" 
    << " Brureaucrat : " << _name << " Grade : " << _grade 
    << std::endl;
}

// Methods -------------------------------

std::string const   Bureaucrat::getName() const
{
    return(_name);
}
unsigned int        Bureaucrat::getGrade() const
{
    return(_grade);
}

void            Bureaucrat::setGrade(unsigned int new_grade)
{
    if (new_grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (new_grade > 150)
        throw Bureaucrat::GradeTooHighException();
    _grade = new_grade;
}

void            Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooHighException();
    _grade++;
}
void            Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooLowException();
    _grade--;
}