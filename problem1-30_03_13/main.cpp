#include <cg/operations/orientation.h>
#include <cg/io/point.h>
#include <iostream>
#include <random>
#include <functional>
#include <gmpxx.h>

cg::orientation_t inaccurate_orientation(cg::point_2 const & a, cg::point_2 const & b, cg::point_2 const & c) {
    double res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (res > 0) {
        return cg::CG_LEFT;
    }
    if (res < 0) {
        return cg::CG_RIGHT;
    }
    return cg::CG_COLLINEAR;
}

int main() {
    std::mt19937 generator;
    std::uniform_real_distribution<> distribution;

    auto dice = std::bind(distribution, generator);

    cg::point_2 a(0, 0), b(3, 5);
    cg::point_2 c;
    double m = ((1LL << 20) - 1.) / (1LL << 10);
    
    while (true) {
        a.x = dice() * m;
        a.y = dice() * m;
        b.x = dice() * m;
        b.y = dice() * m;
        c = a + (b - a) * dice();

        if (cg::orientation(a, b, c) != inaccurate_orientation(a, b, c)) {
            std::cout << "a = " << a << std::endl << "b = " << b << std::endl << "c = " << c << std::endl
                      << "Expected " << cg::orientation(a, b, c) << " but " << inaccurate_orientation(a, b, c) << "found.";
            break;
        }
    }

    return 0;
}