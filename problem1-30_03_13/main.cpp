#include <cg/operations/orientation.h>
#include <iostream>
#include <random>
#include <functional>
#include <gmpxx.h>

cg::orientation_t inaccurate_orientation(cg::point_2 const & a, cg::point_2 const & b, cg::point_2 const & c) {
    double res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (res > 0) {
        return cg::CG_LEFT;
    } 
    if (res > 0) {
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
    
    while (true) {
        double t = dice();
        c = a + (b - a) * t;
        
        if (cg::orientation(a, b, c) != inaccurate_orientation(a, b, c)) {
            std::cout << "c.x = " << c.x << std::endl << "c.y = " << c.y << std::endl;
            std::cout << "Expected " << cg::orientation(a, b, c) << " but " << inaccurate_orientation(a, b, c) << "found";
            break;
        }
    }
    
    return 0;
}