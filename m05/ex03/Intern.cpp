#include "Intern.hpp"

Intern::Intern()
{
        std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &toCopy)
{
        std::cout << "Intern copy constructor called" << std::endl;
        *this = toCopy;
}

Intern::~Intern()
{
        std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
        std::cout << "Intern assignment operator called" << std::endl;
        (void) other;
        return *this;
}

int Intern::getFormIndex(const std::string& f_name) const
{
        std::string forms[NUM_FORMS] = 
        {
                "robotomy request",
                "shrubbery creation",
                "presidential pardon"
        };

        std::string f_name_lower = f_name;
        for (size_t i = 0; i < f_name_lower.length(); i++)
                f_name_lower[i] = std::tolower(f_name_lower[i]);

        for (int i = 0; i < NUM_FORMS; i++)
                if (forms[i] == f_name_lower)
                        return i;

        return -1;
}

AForm* Intern::makeForm(const std::string& f_name, const std::string& target) const
{
    // Tableau de pointeurs sur fonctions membres
    typedef AForm* (Intern::*FormCreator)(const std::string&) const;
    static const FormCreator formCreators[NUM_FORMS] = 
        {
                &Intern::createRobotomyRequestForm,
                &Intern::createShrubberyCreationForm,
                &Intern::createPresidentialPardonForm
        };

    int index = getFormIndex(f_name);
    if (index < 0)
        throw Intern::BadFormNameException();

    AForm *new_form = (this->*formCreators[index])(target);
    std::cout << "Intern creates " << f_name << std::endl;
    return new_form;
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

const char *Intern::BadFormNameException::what() const throw()
{
        return ("BadFormNameException: The Intern cannot create the form");
}