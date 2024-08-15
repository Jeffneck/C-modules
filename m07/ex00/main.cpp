#include "templates.hpp"
#include <iostream>

int main() {
    std::cout << "----Test avec des entiers" << std::endl;
    int a = 10;
    int b = 20;

    std::cout << "Avant swap : a = " << a << ", b = " << b << std::endl;
    std::cout << "Max(a, b) = " << my::max(a, b) << std::endl;
    std::cout << "Min(a, b) = " << my::min(a, b) << std::endl;

    my::swap(a, b);
    std::cout << "Après swap : a = " << a << ", b = " << b << std::endl;

    std::cout << "\n----Test avec des doubles" << std::endl;
    double x = 3.14;
    double y = 2.71;

    std::cout << "Avant swap : x = " << x << ", y = " << y << std::endl;
    std::cout << "Max(x, y) = " << my::max(x, y) << std::endl;
    std::cout << "Min(x, y) = " << my::min(x, y) << std::endl;

    my::swap(x, y);
    std::cout << "Après swap : x = " << x << ", y = " << y << std::endl;

    std::cout << "\n----Test avec des chaînes de caractères" << std::endl;
    std::string str1 = "apple";
    std::string str2 = "banana";

    std::cout << "Avant swap : str1 = " << str1 << ", str2 = " << str2 << std::endl;
    std::cout << "Max(str1, str2) = " << my::max(str1, str2) << std::endl;
    std::cout << "Min(str1, str2) = " << my::min(str1, str2) << std::endl;

    my::swap(str1, str2);
    std::cout << "Après swap : str1 = " << str1 << ", str2 = " << str2 << std::endl;

    return 0;
}