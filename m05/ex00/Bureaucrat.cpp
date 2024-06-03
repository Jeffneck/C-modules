#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unamed"), _grade(150)
{
    std::cout << "Default constructor called -" 
    << *this 
    << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): _name(name)
{
    this->setGrade(grade);
    std::cout << "Constructor called -" << *this << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &to_copy) : _name(to_copy.getName())
{
    this->setGrade(to_copy.getGrade());
    std::cout << "Copy constructor called -" << *this << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called -" << *this << std::endl;
}

// Methods -------------------------------

void    Bureaucrat::announce() const
{
    std::cout << *this << std::endl;
}

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
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
    std::cout << "Grade successfully decremented " << std::endl;
}
void            Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    std::cout << "Grade successfully incremented " << std::endl;
}

//surcharges

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Assignement operator called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return (*this);
}

std::ostream&   operator<<( std::ostream &os, const Bureaucrat &to_display )
{
    os << "Name : " << to_display.getName() << ", Grade : " << to_display.getGrade();
    return(os);
}