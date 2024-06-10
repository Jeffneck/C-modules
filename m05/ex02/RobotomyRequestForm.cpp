#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const std::string target) : AForm(name, 72, 45) , _target(target)
{
    std::cout << "RobotomyRequestForm Default constructor called : "<< *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy) : AForm(to_copy), _target(to_copy.getTarget())
{
    std::cout << "RobotomyRequestForm Default constructor called : "<< *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "RobotomyRequestForm Assignement operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//special function
void		RobotomyRequestForm::randomRobotomy() const
{
    srand((unsigned)time(NULL));
    int nbgen = rand() % 2;
    if (nbgen == 0)
        


}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try{
        AForm::beExecuted(executor); //throw if executor can t exec form and if form is already signed.
    }
    catch(std::exception& e){ 
        std::cerr << "Exception: " << e.what() << std::endl;
        return ;
    }

    try {
        this->randomRobotomy();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

const std::string   RobotomyRequestForm::getTarget() const
{
    return(_target);
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& to_display)
{
    os << static_cast<const AForm&>(to_display);
    os << " Target: " << to_display.getTarget();
    return os;
}
