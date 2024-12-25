#include "app.h"
#include <cassert>
#include <iostream>

int g(std::vector<int> a, std::vector<int> b);

void test() {
    std::cout << std::endl;
    int a;
    a  = g({3, 5}, {2, 4});
    std::cout << "g({3, 5}, {2, 4}) :" << a << " Expected :" << 105 << std::endl;
    std::cout << std::endl;
    a  = g({2, 2}, {2, 2});
    std::cout << "g({2, 2}, {2, 2}) :" << a << " Expected :" << 6 << std::endl;
    std::cout << std::endl;
    a = g({1, 1}, {1, 1});
    std::cout << "g({1, 1}, {1, 1}) :" << a << " Expected :" << 2 << std::endl;
    std::cout << std::endl;
    a = g({4, 3}, {3, 2});
    std::cout << "g({4, 3}, {3, 2}) :" << a << " Expected :" << 35 << std::endl;
        std::cout << std::endl;


//     assert(g({3, 5}, {2, 4}) == 105);
//     assert(g({2, 2}, {2, 2}) == 6);
//     assert(g({1, 1}, {1, 1}) == 2);
//     assert(g({4, 3}, {3, 2}) == 35);
//     assert(g({5}, {5}) == 70);
//     assert(g({1}, {1}) == 1);
//     assert(g({10}, {10}) == 64); // Modulo 256 wraps around
}

int main() {
    test();
    return 0;
}