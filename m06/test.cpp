#include <iostream>
#include <iomanip>  // Nécessaire pour std::fixed et std::setprecision>

int main() {
    double nombre = 12354646.456789;

    // Affichage sans formatage
    std::cout << "Sans formatage : " << nombre << std::endl;

    // Affichage avec std::fixed et std::setprecision
    // std::cout << std::fixed << std::setprecision(2);
    std::cout << std::fixed;
    std::cout << "Avec std::fixed et std::setprecision(2) : " << nombre << std::endl;

    return 0;
}