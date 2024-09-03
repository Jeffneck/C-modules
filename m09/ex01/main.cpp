#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cctype> // pour std::isdigit
#include <cstdlib> // pour std::stoi

// Fonction pour évaluer une expression RPN
int evaluateRPN(const std::string& expression) {
    std::stringstream ss(expression);
    std::stack<int> stack;
    std::string token;

    while (ss >> token) {
        std::cout << "token is : "<<token << std::endl;//
        if(token.size() > 2 || token.size() < 1 || !token[0])
            throw std::invalid_argument("Error: Invalid token size" + token);
        else if(token.size() > 1) //attention au cas des nb negatifs
        {
            for(std::size_t i = 0; i < token.size(); i++)
            {
                if(!std::isdigit(token[i]))
                   throw std::invalid_argument("Error: Invalid token" + token); 
            }
        }


        if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Si le token est un nombre, le convertir et le pousser sur la pile
            stack.push(std::stoi(token));
        } else {
            // Sinon, le token est un opérateur
            if (stack.size() < 2)
                throw std::invalid_argument("Error: An operator need at least 2 operands in the stack" + token); //pas assez d'operandes pour traiter un operateur

            int b = stack.top(); stack.pop(); // Opérande 2
            // std::cout << "test" << std::endl;//
            int a = stack.top(); stack.pop(); // Opérande 1

            // Effectuer l'opération
            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                stack.push(a / b);
            } else {
                throw std::invalid_argument("Error: Invalid token2 " + token);
            } //verifier les cas d' overflows potentiels 
        }
    }

    // Le résultat final doit être le seul élément restant dans la pile
    return stack.top();
}

// void    detectIncorrectChar(std::string &expression)
// {
//     for(std::size_t i = 0; i < expression.size(); i++)
//     {
//         if(!std::isdigit(expression[i]) && !std::isoperator(expression[i]))
//             throw std::invalid_argument("Unknown operator: " + token);
//     }
// }


int main() {
    // std::string expression = "3 4 + 2 * 7 /";
    // std::string expression = "5 1 2 + 4 * + 3 -";
    // std::string expression = "8 4 2 / 3 + *";
    // std::string expression = "8 a 4 2 / 3 + *"; //err detectee
    // std::string expression = "a 8 4 2 / 3 + *"; //err detectee
    // std::string expression = "8 4 2 / 3 + * *"; //err detectee trop d' operandes et donc stack < 2
    std::string expression = "+ 8 4 2 / 3 + *"; //err detectee operation sur stack < 2 
    // std::string expression = "a 4 2 / 3 + *"; //erreur de segmentation
    // std::string expression = "4 2 a / 3 + *"; //unknown operator
    // std::string expression = "8 4 2a / 3 + *"; //le a est ignore et le calcul fonctionne
    // std::string expression = "4 2a / 3 + *"; //segfault
    // std::string expression = "+++ 8 4 2 / 3 + *"; //erreur de segmentation
    
    // try{
    //     detectIncorrectChar(expression);
    // }
    // catch(std::exception &e)
    // {
    //     std::cerr << "Error" << std::endl;
    //     return(1);
    // }

    try {
        int result = evaluateRPN(expression);
        std::cout << "The result of the RPN expression is: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
