#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <cctype>  // Pour std::isprint

class ScalarConverter {
public:
    // La méthode convert qui prend une chaîne de caractères en entrée
    static void convert(const std::string &literal) {
        detectOverflow(literal);
        if(charDetected(literal))
            return;
        detectImpossibleConversion(literal);
        convertToInt(literal);
        convertToFloat(literal);
        convertToDouble(literal);
        convertToChar(literal);
    }
    class OverflowException: public std::exception {
        public:
            const char *what() const throw(); 
    };
    
    class ImpossibleConversionException: public std::exception {
        public:
            const char *what() const throw(); 
    };

private:
    // Constructeur privé pour empêcher l'instanciation
    ScalarConverter() {}

    static void detectImpossibleConversion(const std::string &literal) {
        std::string low_l = strToLower(literal);

        // Vérification pour les valeurs spéciales
        if (low_l == "inf" || low_l == "-inf" || low_l == "+inf" || low_l == "nan" ||
            low_l == "inff" || low_l == "-inff" || low_l == "+inff" || low_l == "nanf") {
            return;
        }

        // Vérifier si '+' ou '-' est en début de chaîne
        if ((literal[0] == '+' || literal[0] == '-') && literal.size() > 1) {
            std::string::size_type i;
            for (i = 1; i < literal.size(); ++i) {
                if (literal[i] == '+' || literal[i] == '-') {
                    throw ScalarConverter::ImpossibleConversionException();
                }
            }
        }

        bool point_found = false;
        std::string::size_type i;
        for (i = 0; i < literal.size(); ++i) {
            char c = literal[i];

            // Si ce n'est pas un chiffre, un point, un 'f', un '+' ou un '-'
            if (!std::isdigit(c) && c != '.' && c != 'f' && c != '+' && c != '-') {
                throw ScalarConverter::ImpossibleConversionException();
            }

            // Vérifier la position de 'f'
            if (c == 'f' && i != literal.size() - 1) {
                throw ScalarConverter::ImpossibleConversionException();
            }

            // Vérifier s'il y a plus d'un point
            if (c == '.') {
                if (point_found) {
                    throw ScalarConverter::ImpossibleConversionException();
                }
                point_found = true;
            }
        }

        // Si un 'f' est présent mais pas en dernière position
        if (literal.find('f') != std::string::npos && literal[literal.size() - 1] != 'f') {
            throw ScalarConverter::ImpossibleConversionException();
        }
    }
    
    static void detectOverflow(const std::string &literal) 
    {
        std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE)
            throw ScalarConverter::OverflowException();
    }

    static void convertToInt(const std::string &literal) {
        std::stringstream ss(literal);
        int intValue;
        if (ss >> intValue) {
            std::cout << "int: " << intValue << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }
    }

    static bool charDetected(const std::string &literal)
    {
        bool	is_char = (literal.length() == 1 && !std::isdigit(literal[0]));
        if (!is_char)
            return (0);
        char     charValue = literal[0];
        int     asciiValue = static_cast<int>(charValue);

        std::ostringstream  oss;
        oss << asciiValue;
        std::string new_literal = oss.str();

        convertToInt(new_literal);
        convertToFloat(new_literal);
        convertToDouble(new_literal);
        convertToChar(new_literal);
        return (1);
    }

    static void convertToFloat(const std::string &literal) {
        std::stringstream ss(literal);
        float floatValue;
        if (ss >> floatValue) {
            std::cout << std::fixed << std::setprecision(choosePrecision(literal));
            std::cout << "float: " << floatValue << "f" << std::endl;
        } else {
            if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
                std::cout << "float: " << literal << std::endl;
            } 
            else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
                std::cout << "float: " << literal << "f" << std::endl;
            }
            else {
                std::cout << "float: impossible" << std::endl;
            }
        }
    }
    static int choosePrecision(const std::string &literal) {
        int	i = 0;

        if (literal.find_first_of('.') == std::string::npos)
            return (1);
        for (size_t j = literal.find_first_of('.'); j < literal.length(); j++)
        {
            if (std::isdigit(literal[j]))
                i++;
        }
        if (i == 0)
            return(1);
        return (i);
    }

    static std::string strToLower(const std::string &literal) {
        std::string low_l = literal;
        for (size_t i = 0; i < low_l.length(); i++)
		    low_l[i] = std::tolower(static_cast<unsigned char>(literal[i]));
        return (low_l);
    }


    static void convertToDouble(const std::string &literal) {
        std::stringstream ss(literal);
        double doubleValue;
        if (ss >> doubleValue) {
            std::cout << std::fixed << std::setprecision(choosePrecision(literal));
            std::cout << "double: " << doubleValue << std::endl;
        } 
        else
        {
            std::string low_l = strToLower(literal);
            if (low_l == "-inff" || low_l == "+inff" || low_l == "nanf") {
                std::cout << "double : " << low_l.substr(0, low_l.size() - 1) << std::endl;
            } 
            else if (low_l == "-inf" || low_l == "+inf" || low_l == "nan") {
                std::cout << "double : " << low_l << std::endl;
            }
            else {
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

const char*	ScalarConverter::OverflowException::what( void ) const throw()
{
	return ("Error: The conversion will cause an overfow, try to pass a literal in range");
}

const char*	ScalarConverter::ImpossibleConversionException::what( void ) const throw()
{
	return ("Error: The conversion is impossible, the input don't match with any of this types {char, int, float, double}");
}

int main(int ac, char **av) 
{
    if(ac == 2)
        try {ScalarConverter::convert(av[1]);}
    
    catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

    return 0;
}
