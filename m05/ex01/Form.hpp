#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form 
{
    private :
        const std::string   _name;
        bool                _is_signed;
        const unsigned int  _grade_sign;
        const unsigned int  _grade_exec;

    public :
        Form(const std::string name, const unsigned int _grade_sign, const unsigned int _grade_exec);
        Form(const Form& to_copy);
        virtual ~Form();

        Form& operator=(Form& other);
        
        void                    announce()      const;
        const std::string       getName()       const;
        bool                    getSigned()     const;
        unsigned int      getSignGrade()  const;
        unsigned int      getExecGrade()  const;

        void                    beSigned(const Bureaucrat& bureaucrat);
        void                    signForm(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
                public :
                    const char  *what() const throw(){
            			return "Form::GradeTooHigh";
        			};
        };
        class GradeTooLowException : public std::exception
        {
                public :
                    const char  *what() const throw(){
            			return "Form::GradeTooLow";
        			};
        };

};

std::ostream&   operator<<(std::ostream& os, const Form& to_display);


#endif