#include "../src/app.h"

#include <iostream>
#include <vector>
#include <cassert>

// Include the function to test
// int f(std::vector<int> a); // Assuming the function is defined in the same file or included

int f(std::vector<int> a);

void test_empty() {
    std::vector<int> a;
    assert(f(a) == 0);
}

void test_no_land() {
    std::vector<int> a = {0, 0, 0};
    assert(f(a) == 0);
}

void test_single_land() {
    std::vector<int> a = {static_cast<int>(0b00000000000000000000000000000001)};
    assert(f(a) == 1);
}

void test_single_landmass_size_4() {
    std::vector<int> a = {static_cast<int>(0b00000000000000000000000000001111)};
    assert(f(a) == 4);
}

void test_example() {
    std::vector<int> a = {
        static_cast<int>(0b00000000001111000000000011110000),
        static_cast<int>(0b00000000001111000000000011110000),
        static_cast<int>(0b11110000000000001111000000000000)
    };
    assert(f(a) == 8);
}

void test_separate_landmasses() {
    std::vector<int> a = {
        static_cast<int>(0b00000000000011000000000000001100),
        static_cast<int>(0b00000000000000000000000000000000),
        static_cast<int>(0b00000000000011000000000000001100)
    };
    assert(f(a) == 4);
}

void test_larger_landmass_vertical() {
    std::vector<int> a = {
        static_cast<int>(0b00000000000000000000000000000001),
        static_cast<int>(0b00000000000000000000000000000001),
        static_cast<int>(0b00000000000000000000000000000001),
        static_cast<int>(0b00000000000000000000000000000001)
    };
    assert(f(a) == 4);
}

void test_larger_landmass_complex() {
    std::vector<int> a = {
        static_cast<int>(0b00011000000000000000000000000000),
        static_cast<int>(0b00011000000000000000000000000000),
        static_cast<int>(0b00011110000000000000000000000000),
        static_cast<int>(0b00000000000000000000000000000000),
        static_cast<int>(0b11100000000000000000000000000000),
    };
    assert(f(a) == 7);
}

int main() {
    test_empty();
    test_no_land();
    test_single_land();
    test_single_landmass_size_4();
    test_example();
    test_separate_landmasses();
    test_larger_landmass_vertical();
    test_larger_landmass_complex();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}