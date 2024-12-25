#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdexcept>
#include <cassert>
#include <iostream>

#include "../src/app.h"

void test_g() {
    std::cout << "started all test cases" << std::endl;
    assert(g("0") == 0);
    assert(g("1") == 5);
    assert(g("2") == 6);
    assert(g("3") == 7);
    assert(g("4") == 8);
    assert(g("5") == 9);
    assert(g("6") == 10);
    assert(g("7") == 10);
    assert(g("8") == 11);
    assert(g("9") == 11);
    assert(g("10") == 12);

    assert(g("20") == 16);
    assert(g("25") == 18);
    assert(g("100") == 32);
    assert(g("1000") == 95);
    assert(g("10000") == 289);
    assert(g("24") == 17);
    assert(g("26") == 18);

    // Test cases with many zeros
    assert(g("1000000") == 2838);

    // Test cases with larger intermediate values
    assert(g("500") == 68);
    assert(g("999") == 95);

    // Edge case with slightly larger numbers
    assert(g("100000") == 902);
    assert(g("10000000") == 8955);
}

int main() {
    test_g();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}