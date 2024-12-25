#include "app.h"
#include <cassert>
#include <iostream>

void test() {
    std::cout << "g(0):" << g("0") << " Expected :" << 0 << std::endl;
    std::cout << "g(1):" << g("1") << " Expected :" << 5 << std::endl;
    std::cout << "g(2):" << g("2") << " Expected :" << 10 << std::endl;
    std::cout << "g(3):" << g("3") << " Expected :" << 15 << std::endl;  
    std::cout << "g(4):" << g("4") << " Expected :" << 20 << std::endl;  
    std::cout << "g(5):" << g("5") << " Expected :" << 25 << std::endl;
}

int main() {
    test();
    return 0;
}