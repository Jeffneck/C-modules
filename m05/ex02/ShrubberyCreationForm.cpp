# include "ShrubberyCreationForm.hpp"

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

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

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

/*
               ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
    \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_*/