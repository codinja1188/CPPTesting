#include "app.h"
#include <cassert>
#include <iostream>

void test() {


    std::cout << "g(0):" << g("0") << " Expected :" << 0 << std::endl;
    std::cout << "g(1):" << g("1") << " Expected :" << 5 << std::endl;
    std::cout << "g(2):" << g("2") << " Expected :" << 6 << std::endl;
    std::cout << "g(3):" << g("3") << " Expected :" << 7 << std::endl;  
    std::cout << "g(4):" << g("4") << " Expected :" << 8 << std::endl;  
    std::cout << "g(5):" << g("5") << " Expected :" << 9 << std::endl;
    std::cout << "g(6):" << g("6") << " Expected :" << 10 << std::endl;
    std::cout << "g(7):" << g("7") << " Expected :" << 11 << std::endl;
    std::cout << "g(8):" << g("8") << " Expected :" << 12 << std::endl;
    std::cout << "g(9):" << g("9") << " Expected :" << 13 << std::endl;
    std::cout << "g(10):" << g("10") << " Expected :" << 14 << std::endl;

}

int main() {
    test();
    return 0;
}