#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm 
{
    private :
        const std::string   _name;
        bool                _is_signed;
        const unsigned int  _grade_sign;
        const unsigned int  _grade_exec;

    public :
        AForm(const std::string name, const unsigned int _grade_sign, const unsigned int _grade_exec);
        AForm(const AForm& to_copy);
        virtual ~AForm();

        AForm& operator=(AForm& other);
        
        void                    announce()      const;
        const std::string       getName()       const;
        bool                    getSigned()     const;
        unsigned int            getSignGrade()  const;
        unsigned int            getExecGrade()  const;

        void                        beSigned(const Bureaucrat& bureaucrat);
        void                        beExecuted(const Bureaucrat& bureaucrat) const;
        virtual void                execute(Bureaucrat const &executor) const = 0;
        virtual const std::string   getTarget() const = 0;


        class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		class SignatureException: public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream&   operator<<(std::ostream& os, const AForm& to_display);


#endif