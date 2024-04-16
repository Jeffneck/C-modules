// #include <iostream>

// class A {
// public:
//     int x;
    
//     A(int value) : x(value) {} // Constructeur de A qui initialise x
// };

// class B : public A {
// public:
//     B(int value) : A(value) {
//         x = value * 2; // Modifie la valeur de x dans le constructeur de B
//     }
// };

// int main() {
//     B b(5);
//     std::cout << "Value of x in B: " << b.x << std::endl; // Affichera 10
//     std::cout << "Value of x in A: " << b.A::x << std::endl; // Affichera 5
//     return 0;
// }

// -------------------------------------------------

// #include <iostream>

// class A {
// public:
//     int x;
    
//     A() {}
    
//     void initializeX(int value) {
//         x = value;
//     }
// };

// class B : public A {
// public:
//     B(int value) {
//         initializeX(value * 2); // Appelle la méthode de la classe de base pour initialiser x
//     }
// };

// int main() {
//     B b(5);
//     std::cout << "Value of x in B: " << b.x << std::endl; // Affichera 10
//     std::cout << "Value of x in A: " << b.A::x << std::endl; // Affichera 5
//     return 0;
// }


// -------------------------------------------------


#include <iostream>

class A {
public:
    int x;
    
    A(int value) : x(value) {}
};

class B : public A {
public:
    B(int value) : A(value), x(value * 2) {} // Appelle le constructeur de A avec la valeur originale, puis modifie x dans B

    // Si vous souhaitez accéder à x de A à travers une instance de B, vous pouvez définir une méthode dans B
    int getXFromA() const {
        return A::x;
    }
};

int main() {
    B b(5);
    std::cout << "Value of x in B: " << b.x << std::endl; // Affichera 10
    std::cout << "Value of x in A: " << b.getXFromA() << std::endl; // Affichera 5
    return 0;
}

// comment modifier l' attribut d' une sous classe sans modifier la valeur de l' attribut dans sa classe mere