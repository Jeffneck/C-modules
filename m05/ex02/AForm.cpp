# include "AForm.hpp"

AForm::AForm(const std::string name, const unsigned int grade_sign, const unsigned int grade_exec)
: _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw (GradeTooHighException());
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw (GradeTooLowException());
    std::cout << "AForm Default constructor called : "<< *this << std::endl;
}

AForm::AForm(const AForm& to_copy)
: _name(to_copy.getName()), _is_signed(to_copy.getSigned()), _grade_sign(to_copy.getSignGrade()), _grade_exec(to_copy.getExecGrade())
{
    std::cout << "AForm Copy constructor called : "<< *this << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called : "<< *this << std::endl;
}

//Only copy the non-const attributes can be copied after init
AForm& AForm::operator=(AForm& other) 
{
    std::cout << "AForm Assignement operator called" << std::endl;
    if (this != &other)
        _is_signed = other.getSigned();
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const AForm& to_display)
{
    os << " AForm name : " << to_display.getName()
    << ", Grade to sign : " << to_display.getSignGrade()
    << ", Grade to exec : " << to_display.getExecGrade()
    << ", Is already signed ? : " << to_display.getSigned();
    return (os);
}


void                    AForm::announce()      const
{
    std::cout << *this << std::endl;
}

const std::string       AForm::getName()       const
{
    return (_name);
}

bool                    AForm::getSigned()     const
{
    return (_is_signed);
}

unsigned int      AForm::getSignGrade()  const
{
    return (_grade_sign);
}

unsigned int      AForm::getExecGrade()  const
{
    return (_grade_exec);
}

void                    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade_sign)
        _is_signed = true;
    else 
        throw GradeTooLowException();

}
void                    AForm::signForm(const Bureaucrat& bureaucrat)
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

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm::GradeTooHigh");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm::GradeTooLow");
}

void        AForm::tryExecute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > _grade_exec)
        throw AForm::GradeTooLowException();
    else if (!_is_signed)
        throw AForm::SignatureException();
}
