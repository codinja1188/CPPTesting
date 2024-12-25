#include "app.h"
#include <cassert>
#include <iostream>

int g(std::vector<int> a, std::vector<int> b);

void test() {
    std::cout << "g({3, 5}, {2, 4}) :" << g({3, 5}, {2, 4}) << " Expected :" << 105 << std::endl;
    std::cout << "g({2, 2}, {2, 2}) :" << g({2, 2}, {2, 2}) << " Expected :" << 6 << std::endl;
    std::cout << "g({1, 1}, {1, 1}) :" << g({1, 1}, {1, 1}) << " Expected :" << 2 << std::endl;
    std::cout << "g({4, 3}, {3, 2}) :" << g({4, 3}, {3, 2}) << " Expected :" << 35 << std::endl;


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