# include "Form.hpp"

Form::Form(const std::string name, const unsigned int grade_sign, const unsigned int grade_exec)
: _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw (GradeTooHighException());
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw (GradeTooLowException());
    std::cout << "Form Default constructor called : "<< *this << std::endl;
}

Form::Form(const Form& to_copy)
: _name(to_copy.getName()), _is_signed(to_copy.getSigned()), _grade_sign(to_copy.getSignGrade()), _grade_exec(to_copy.getExecGrade())
{
    std::cout << "Form Copy constructor called : "<< *this << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called : "<< *this << std::endl;
}

//Only copy the non-const attributes can be copied after init
Form& Form::operator=(Form& other) 
{
    std::cout << "Assignement operator called" << std::endl;
    if (this != &other)
        _is_signed = other.getSigned();
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Form& to_display)
{
    os << " Form name : " << to_display.getName()
    << ", Grade to sign : " << to_display.getSignGrade()
    << ", Grade to exec : " << to_display.getExecGrade()
    << ", Is already signed ? : " << to_display.getSigned();
    return (os);
}


void                    Form::announce()      const
{
    std::cout << *this << std::endl;
}

const std::string       Form::getName()       const
{
    return (_name);
}

bool                    Form::getSigned()     const
{
    return (_is_signed);
}

unsigned int      Form::getSignGrade()  const
{
    return (_grade_sign);
}

unsigned int      Form::getExecGrade()  const
{
    return (_grade_exec);
}

void                    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade_sign)
        _is_signed = true;
    else 
        throw GradeTooLowException();

}
void                    Form::signForm(const Bureaucrat& bureaucrat)
{
    try
    {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
    }
    
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form::GradeTooHigh");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form::GradeTooLow");
}