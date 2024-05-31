# include "Bureaucrat.hpp"

int main() {
    std::cout << "\n-------CONSTRUCT WITH GRADE TOO HIGH----------\n" << std::endl;
    try {
        Bureaucrat a("Nicky Minaj", 151);
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    std::cout << "\n-------CONSTRUCT WITH GRADE TOO LOW----------\n" << std::endl;
    try {
        Bureaucrat b("David Guetta", 0);
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------CONSTRUCT WITH GRADE OK----------\n" << std::endl;
    try {
        Bureaucrat c("Sia", 1);//aucune exception ne sera catch
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    Bureaucrat d("Daft Punk", 1);
    std::cout << "\n-------MODIF GRADE TOO LOW----------\n" << std::endl;
    try {
        d.decrementGrade(); // This will attempt to decrement Sia's grade below 1, which should throw an exception
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    std::cout << "\n-------MODIF GRADE TOO HIGH----------\n" << std::endl;
    try {
        d.setGrade(150);
        d.incrementGrade(); // This will attempt to increment Sia's grade above 150, which should throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    std::cout << "\n-------MODIF GRADE OK----------\n" << std::endl;
    try {
        d.setGrade(100); // This is a valid operation and should not throw any exception
        std::cout << "Grade set to 100 successfully, no exceptions." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    return 0;
}