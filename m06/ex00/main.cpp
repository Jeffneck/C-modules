#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>  // Pour std::isprint

class ScalarConverter {
public:
    // La méthode convert qui prend une chaîne de caractères en entrée
    static void convert(const std::string &literal) {
        // Conversion en int
        convertToInt(literal);
        
        // Conversion en float
        convertToFloat(literal);
        
        // Conversion en double
        convertToDouble(literal);
        
        // Conversion en char
        convertToChar(literal);
    }

private:
    // Constructeur privé pour empêcher l'instanciation
    ScalarConverter() {}

    static void convertToInt(const std::string &literal) {
        std::stringstream ss(literal);
        int intValue;
        if (ss >> intValue) {
            std::cout << "int: " << intValue << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }
    }

    static void convertToFloat(const std::string &literal) {
        std::stringstream ss(literal);
        float floatValue;
        if (ss >> floatValue) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << floatValue << "f" << std::endl;
        } else {
            if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
                std::cout << "float: " << literal << std::endl;
            } else {
                std::cout << "float: impossible" << std::endl;
            }
        }
    }

    static void convertToDouble(const std::string &literal) {
        std::stringstream ss(literal);
        double doubleValue;
        if (ss >> doubleValue) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << doubleValue << std::endl;
        } else {
            if (literal == "-inf" || literal == "+inf" || literal == "nan") {
                std::cout << "double: " << literal << std::endl;
            } else {
                std::cout << "double: impossible" << std::endl;
            }
        }
    }

    static void convertToChar(const std::string &literal) {
        int intValue;
        std::stringstream ss(literal);
        if (ss >> intValue && intValue >= 0 && intValue <= 127) {
            if (std::isprint(intValue)) {
                std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    }
};

int main() {
    ScalarConverter::convert("");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("42");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("a");
    return 0;
}
