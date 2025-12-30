#include "../src/app.h"

#include <iostream>
#include <cassert>

void test_empty() {
    std::vector<int> a = {};
    assert(f(a) == 0);
}

void test_no_land() {
    std::vector<int> a = {0, 0, 0};
    assert(f(a) == 0);
}

void test_single_land() {
    std::vector<int> a = {0b00000000000000000000000000000001};
    assert(f(a) == 1);
}


void test_small_landmass() {
  std::vector<int> a = {static_cast<int>(0b00000000001111000000000011110000),
                        static_cast<int>(0b00000000001111000000000011110000),
                        static_cast<int>(0b11110000000000001111000000000000)};
  assert(f(a) == 8);
}


void test_scattered_land() {
  std::vector<int> a = {static_cast<int>(0b10000000000000000000000000000001),
                        static_cast<int>(0b00000000000000000000000000000000),
                        static_cast<int>(0b00000000000000000000000000000001)};
  assert(f(a) == 1);
}


void test_edge_land() {
  std::vector<int> a = {static_cast<int>(0b11111111111111111111111111111111),
                        static_cast<int>(0b00000000000000000000000000000000),
                        static_cast<int>(0b00000000000000000000000000000000)};
  assert(f(a) == 32);
}


void test_alternating_land_water() {
    std::vector<int> a = {
        static_cast<int>(0b10101010101010101010101010101010),
        static_cast<int>(0b01010101010101010101010101010101),
        static_cast<int>(0b10101010101010101010101010101010)
    };
    assert(f(a) == 1);
}


void test_all_land() {
    std::vector<int> a = {static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF)};
    assert(f(a) == 96);
}

void test_larger_landmass(){
    std::vector<int> a = {static_cast<int>(0xFFFFFFFF),
                         static_cast<int>(0xFFFFFFFF),
                         static_cast<int>(0x0000FFFF),
                         static_cast<int>(0xFFFFFFFF),
                         static_cast<int>(0x0000FFFF)};
    assert(f(a) == 128);
}

void test_vertical_land(){
    std::vector<int> a(100, 0);
    for(int i = 0; i < 100; i++){
        a[i] |= (1 << 15);
    }
    assert(f(a) == 100);
}

void test_diagonal_land(){
    std::vector<int> a(32,0);
    for(int i = 0; i < 32; ++i){
        a[i] |= (1 << i);
    }
    assert(f(a) == 1);
}



int main() {
    test_empty();
    test_no_land();
    test_single_land();
    test_small_landmass();
    test_scattered_land();
    test_edge_land();
    test_alternating_land_water();
    test_all_land();
    test_larger_landmass();
    test_vertical_land();
    test_diagonal_land();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
