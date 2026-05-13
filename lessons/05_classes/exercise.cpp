#include <iostream>
#include <cmath>

struct Vec2 {
    float x, y;

    // TODO 1: default constructor → (0, 0) using delegation
    // TODO 2: two-arg constructor
    // TODO 3: explicit single-arg constructor → (scalar, scalar)

    // TODO 4: member operators +=, -=, *=(scalar)

    // TODO 5: length()
};

// TODO 5: free operators +, -, *(v,s), *(s,v), ==, !=
// TODO 6: operator<<

int main() {
    Vec2 zero;
    Vec2 a(1.0f, 2.0f);
    Vec2 b(3.0f, 4.0f);

    // arithmetic
    std::cout << a + b << "\n";         // (4, 6)
    std::cout << b - a << "\n";         // (2, 2)
    std::cout << a * 2.0f << "\n";      // (2, 4)
    std::cout << 2.0f * a << "\n";      // (2, 4)

    // equality
    std::cout << (a == a) << "\n";      // 1
    std::cout << (a != b) << "\n";      // 1

    // length
    std::cout << b.length() << "\n";    // 5

    // explicit: uncomment to verify compile error
    // Vec2 bad = 1.0f;

    // explicit: this should work
    Vec2 splat(3.0f);
    std::cout << splat << "\n";         // (3, 3)

    // lerp: a + (b - a) * 0.5f
    Vec2 mid = a + (b - a) * 0.5f;
    std::cout << mid << "\n";           // (2, 3)
}
