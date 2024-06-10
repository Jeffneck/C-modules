#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target) : AForm(name, 145, 137) , _target(target)
{
    std::cout << "ShrubberyCreationForm Default constructor called : "<< *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy) : AForm(to_copy), _target(to_copy.getTarget())
{
    std::cout << "ShrubberyCreationForm Default constructor called : "<< *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "ShrubberyCreationForm Assignement operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void		ShrubberyCreationForm::generateFile() const
{
    std::string new_filename(_target + "_shrubbery");
    std::ofstream flux(new_filename.c_str());
    //!flux is true whenever flux.badbit() or flux.failbit show some kind of error
    if (!flux)
        throw std::runtime_error("Failed to open file: " + new_filename);

    flux << "               ,@@@@@@@," << std::endl;
	flux << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	flux << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	flux << "   ,%&%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	flux << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	flux << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	flux << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	flux << "       |o|        | |         | |" << std::endl;
	flux << "       |.|        | |         | |" << std::endl;
	flux << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

    if (!flux)// Check for errors during the write operation
        throw std::runtime_error("Failed to write to file: " + new_filename);
    flux.close();
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    try{
        AForm::beExecuted(executor); //throw if executor can t exec form and if form is already signed.
    }
    catch(std::exception& e){ 
        std::cerr << "Exception: " << e.what() << std::endl;
        return ;
    }

    try {
        this->generateFile();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

const std::string   ShrubberyCreationForm::getTarget() const
{
    return(_target);
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& to_display)
{
    os << static_cast<const AForm&>(to_display);
    os << " Target: " << to_display.getTarget();
    return os;
}
