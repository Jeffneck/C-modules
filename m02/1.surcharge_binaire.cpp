#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Surcharge de l'opérateur d'addition
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Surcharge de l'opérateur de soustraction
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // Surcharge de l'opérateur de multiplication par un scalaire
    Point operator*(int scalar) const {
        return Point(x * scalar, y * scalar);
    }

    // Surcharge de l'opérateur de comparaison
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Surcharge de l'opérateur de sortie
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point a(2, 3);
    Point b(4, 5);

    // Utilisation des différentes surcharges
    Point c = a + b;
    Point d = b - a;
    Point e = a * 2;

    std::cout << "a + b = " << c << std::endl;
    std::cout << "b - a = " << d << std::endl;
    std::cout << "a * 2 = " << e << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;

    return 0;
}