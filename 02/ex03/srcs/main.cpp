#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(1.0f, 0.0f);
    Point c(0.0f, 1.0f);

    Point p1(0.1f, 0.1f);
    std::cout << (bsp(a, b, c, p1) ? "Point p1 is inside the triangle" : "Point p1 is outside the triangle") << std::endl;

    Point p2(0.5f, 0.5f);
    std::cout << (bsp(a, b, c, p2) ? "Point p2 is inside the triangle" : "Point p2 is outside the triangle") << std::endl;

    Point p3(-0.1f, 0.1f);
    std::cout << (bsp(a, b, c, p3) ? "Point p3 is inside the triangle" : "Point p3 is outside the triangle") << std::endl;

    Point p4(1.0f, 1.0f);
    std::cout << (bsp(a, b, c, p4) ? "Point p4 is inside the triangle" : "Point p4 is outside the triangle") << std::endl;

    Point p5(0.0f, 0.0f);
    std::cout << (bsp(a, b, c, p5) ? "Point p5 is inside the triangle" : "Point p5 is outside the triangle") << std::endl;

    Point p6(0.5f, 0.0f);
    std::cout << (bsp(a, b, c, p6) ? "Point p6 is inside the triangle" : "Point p6 is outside the triangle") << std::endl;

    return 0;
}
