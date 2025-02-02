#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private : 
        const std::string   _target;

    public :
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& to_copy);
        PresidentialPardonForm& operator=(PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();

        void		            execute(Bureaucrat const &executor) const;
        const std::string       getTarget() const;
};

std::ostream&   operator<<(std::ostream& os, const PresidentialPardonForm& to_display);


#endif