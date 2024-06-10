#include <exception>
#include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RED "\x1b[31;1m"
# define GREEN "\e[1;32m"
# define RESET "\x1b[0m"


// int main() {
//     try {
//         std::cout << "\n-------CONSTRUCT FORM WITH GRADE TOO LOW----------\n" << std::endl;
//         Form form1("Contract", 151, 100);
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     try {
//         std::cout << "\n-------CONSTRUCT FORM WITH GRADE TOO HIGH----------\n" << std::endl;
//         Form form2("Contract", 100, 0);
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     try {
//         std::cout << "\n-------CONSTRUCT WITH GRADE OK----------\n" << std::endl;
//         Form form3("Contract", 100, 100);
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n-------TEST BE SIGNED KO----------\n" << std::endl;

//     try {
//         Bureaucrat bureaucrat("John", 51);
//         Form form("Contract", 50, 100);
//         std::cout << "Before being signed: " << form.getSigned() << std::endl;
//         form.beSigned(bureaucrat);
//         std::cout << "After being signed: " << form.getSigned() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n-------TEST BE SIGNED OK----------\n" << std::endl;

//     try {
//         Bureaucrat bureaucrat("Betty", 50);
//         Form form("Contract", 50, 100);
//         std::cout << "Before being signed: " << form.getSigned() << std::endl;
//         form.beSigned(bureaucrat);
//         std::cout << "After being signed: " << form.getSigned() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n-------TEST SIGN FORM KO----------\n" << std::endl;

//     try {
//         Bureaucrat bureaucrat("Alice", 120);
//         Form form("Contract", 100, 100);
//         std::cout << "Before being signed: " << form.getSigned() << std::endl;
//         form.signForm(bureaucrat);
//         std::cout << "After being signed: " << form.getSigned() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n-------TEST SIGN FORM OK----------\n" << std::endl;

//     try {
//         Bureaucrat bureaucrat("Fredo", 100);
//         Form form("Contract", 100, 100);
//         std::cout << "Before being signed: " << form.getSigned() << std::endl;
//         form.signForm(bureaucrat);
//         std::cout << "After being signed: " << form.getSigned() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }

int	main( void )
{

	std::cout << GREEN << "\n!----- WORKING TESTS -----!" << RESET << std::endl;
	{
		Bureaucrat				test("Pedro", 1);

		// PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		// RobotomyRequestForm		rob_form("Robotomy", "patient");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");

		// std::cout << "\n" << std::endl;
		// test.signForm(pres_form);
		// test.executeForm(pres_form);

		// std::cout << "\n" << std::endl;
		// test.signForm(rob_form);
		// test.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		test.signForm(shru_form);
		test.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}

	std::cout << RED << "\n!----- FAILING TESTS : SIGNATURE -----!" << RESET << std::endl;
	{
		Bureaucrat				pedro("Pedro", 1);
		// PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		// RobotomyRequestForm		rob_form("Robotomy", "patient");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");

		// std::cout << "\n" << std::endl;
		// pedro.executeForm(pres_form);

		// std::cout << "\n" << std::endl;
		// pedro.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		pedro.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}

	std::cout << RED << "\n!----- FAILING TESTS : GRADE -----!" << RESET << std::endl;
	{
		Bureaucrat				pedro("Pedro", 146);
		// Bureaucrat				test2("Jeannot", 73);
		// Bureaucrat				test3("Colombo", 25);
		Bureaucrat				Rico("Rico", 1);
		// PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		// RobotomyRequestForm		rob_form("Robotomy", "patient");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");

		// std::cout << "\n" << std::endl;
		// Rico.signForm(pres_form);
		// pedro.executeForm(pres_form);

		// std::cout << "\n" << std::endl;
		// Rico.signForm(rob_form);
		// pedro.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		Rico.signForm(shru_form);
		pedro.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}
	return (0);
}