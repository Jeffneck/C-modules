#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string name, const std::string target) : AForm(name, 25, 5) , _target(target)
{
    std::cout << "PresidentialPardonForm Default constructor called : "<< *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy) : AForm(to_copy), _target(to_copy.getTarget())
{
    std::cout << "PresidentialPardonForm Default constructor called : "<< *this << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "PresidentialPardonForm Assignement operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    try{
        AForm::beExecuted(executor); //throw if executor can t exec form and if form is already signed.
    }
    catch(std::exception& e){ 
        throw;
    }
    std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const std::string   PresidentialPardonForm::getTarget() const
{
    return(_target);
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& to_display)
{
    os << static_cast<const AForm&>(to_display);
    os << " Target: " << to_display.getTarget();
    return os;
}
