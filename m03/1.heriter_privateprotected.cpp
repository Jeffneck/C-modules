#include <iostream>

class A {
private:
    void privateMethod() {
        std::cout << "Je suis une méthode privée de la classe A." << std::endl;
    }

protected:
    void protectedMethod() {
        std::cout << "Je suis une méthode protégée de la classe A." << std::endl;
    }

public:
    void adaptMethod() {
        privateMethod();
        protectedMethod();
    }
};

class B : public A {
public:
    void adaptMethod() {
        std::cout << "J'adapte les méthodes privée et protégée de la classe A dans la classe B." << std::endl;
        // Appel de la méthode protégée de la classe A
        protectedMethod();
        // Pour appeler la méthode privée de la classe A, nous devons utiliser une méthode publique de la classe A
        // Cette méthode est appelée adaptMethod() dans la classe A
        A::adaptMethod();
    }
};

int main() {
    B objB;
    // objB.B::privateMethod();
    // objB.B::protectedMethod();

    objB.A::privateMethod();
    objB.A::protectedMethod();
    
	// objB.adaptMethod();
    // objB.adaptMethod();
    // objB.adaptMethod();
    // objB.adaptMethod();
    return 0;
}