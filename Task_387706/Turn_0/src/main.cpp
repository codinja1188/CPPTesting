#include "app.h"
#include <cassert>
#include <iostream>

void test() {
    std::cout << "g('I'):" << g("I") << " Expected :" << 1 << std::endl;
    std::cout << "g('V'):" << g("V") << " Expected :" << 5 << std::endl;
    std::cout << "g('X'):" << g("X") << " Expected :" << 10 << std::endl;
    std::cout << "g('L'):" << g("L") << " Expected :" << 50 << std::endl;  
    std::cout << "g('C'):" <<g("C") << " Expected :" << 100 << std::endl;  
    std::cout << "g('D'):" << g("D") << " Expected :" << 500 << std::endl;
    std::cout << "g('M'):" << g("M") << " Expected :" << 1000 << std::endl;
}

int main() {
    test();
    return 0;
}