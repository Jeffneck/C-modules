#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Surcharge de l'opérateur d'incrémentation préfixe (++point)
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Surcharge de l'opérateur d'incrémentation postfixe (point++)
    Point operator++(int) {
        Point temp(*this);
        ++(*this);
        return temp;
    }

    // Surcharge de l'opérateur de négation (-point)
    Point operator-() const {
        return Point(-x, -y);
    }

    // Surcharge de l'opérateur de sortie (<<)
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point p(2, 3);

    std::cout << "Original p: " << p << std::endl;

    // Utilisation des opérateurs unaires
    Point q = ++p;
    std::cout << "After pre-increment: " << p << std::endl;
    std::cout << "Result of pre-increment: " << q << std::endl;

    Point r = p++;
    std::cout << "After post-increment: " << p << std::endl;
    std::cout << "Result of post-increment: " << r << std::endl;

    Point s = -p;
    std::cout << "After negation: " << s << std::endl;

    return 0;
}