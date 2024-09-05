#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <cctype> // Pour std::tolower

#define NUM_FORMS 3

class Intern
{
        public : 
                Intern();
                Intern(const Intern &toCopy);
                ~Intern();
                Intern& operator=(const Intern& other);

                int getFormIndex(const std::string& f_name) const;
                AForm* makeForm(const std::string& f_name, const std::string& target) const;

        private :
                AForm* createRobotomyRequestForm(const std::string& target) const;
                AForm* createShrubberyCreationForm(const std::string& target) const;
                AForm* createPresidentialPardonForm(const std::string& target) const;

        class BadFormNameException : public std::exception
        {
                public :
                        const char* what() const throw();
        };
};

#endif // INTERN_HPP