#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    private : 
        const std::string   _target;

    public :
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& to_copy);
        RobotomyRequestForm& operator=(RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();

        void		            execute(Bureaucrat const &executor) const;
        void                    randomRobotomy() const;
        const std::string       getTarget() const;
};

std::ostream&   operator<<(std::ostream& os, const RobotomyRequestForm& to_display);


#endif