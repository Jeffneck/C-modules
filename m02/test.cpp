// #include <math.h>
// #include <stdio.h>
// #include <limits.h>
// #include <stdlib.h>

// int main() {

//     printf( "%f\n", roundf((float)(FLT_MAX + 1000) ));        /* Affiche 4 */
//     return EXIT_SUCCESS;
// }


// #include <iostream>
// #include <limits>

// int main() {
// 	float test = 3.4028333333333333333332e+29;
//     std::cout << "Float max: " << std::numeric_limits<float>::max() << std::endl;
//     std::cout << "Float: " << test << std::endl;
//     return 0;
// }

#include <iostream>
#include <cmath>
#include <limits>

class Fixed {
private:
    int m_fixed_nb;
    const int m_fact_bits = 8; // Exemple: 8 bits pour la partie fractionnaire

public:
    Fixed(const float float_nbr) {
        std::cout << "Float constructor called" << std::endl;

        float convertedFloat = float_nbr * (1 << m_fact_bits); // Convertir le flottant en virgule fixe

        // Vérifier si le flottant converti dépasse les limites de m_fixed_nb
        if (convertedFloat > std::numeric_limits<int>::max()) {
            m_fixed_nb = std::numeric_limits<int>::max();
        } else if (convertedFloat < std::numeric_limits<int>::min()) {
            m_fixed_nb = std::numeric_limits<int>::min();
        } else {
            m_fixed_nb = static_cast<int>(convertedFloat);
        }
    }

    void printValue() {
        std::cout << "m_fixed_nb: " << m_fixed_nb << std::endl;
    }
};

int main() {
    Fixed f1(std::numeric_limits<float>::max()); // Utiliser la valeur maximale d'un float
    f1.printValue();

    Fixed f2(std::numeric_limits<float>::lowest()); // Utiliser la valeur minimale d'un float
    f2.printValue();

    return 0;
}