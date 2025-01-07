#include "../src/app.h"

#include <vector>
#include <cassert>
#include <iostream>

int f(std::vector<int> a);

void test_f() {
    // Test case 1: Empty map
    assert(f({}) == 0);

    // Test case 2: No land
    assert(f({0, 0, 0}) == 0);

    // Test case 3: Single land cell
    assert(f({static_cast<int>(0x80000000), 0, 0}) == 1);
    assert(f({static_cast<int>(0x00000001), 0, 0}) == 1);
    assert(f({0, static_cast<int>(0x00000001), 0}) == 1);
    assert(f({0, 0, static_cast<int>(0x80000000)}) == 1);

    // Test case 4: Single landmass
    assert(f({static_cast<int>(0b00000000001111000000000011110000), 
              static_cast<int>(0b00000000001111000000000011110000),
              static_cast<int>(0b11110000000000001111000000000000)}) == 8);

    // Test case 5: Multiple landmasses
    assert(f({static_cast<int>(0b11000000000000000000000000000000),
              static_cast<int>(0b00000000000000000000000000001100),
              static_cast<int>(0b00000000000000001111000000000000)}) == 4);

    // Test case 6: All land
    std::vector<int> all_land(5, static_cast<int>(0xFFFFFFFF));
    assert(f(all_land) == 5 * 32);
    
    // Test case 7: Land on edges
    assert(f({static_cast<int>(0x80000000), static_cast<int>(0x80000000), static_cast<int>(0x80000000), static_cast<int>(0x00000001), static_cast<int>(0x00000001), static_cast<int>(0x00000001)}) == 3);

    // Test case 8: Diagonal land cells
    assert(f({static_cast<int>(0b10000000000000000000000000000000),
              static_cast<int>(0b01000000000000000000000000000000),
              static_cast<int>(0b00100000000000000000000000000000)}) == 1);
    
    // Test case 9: Complex shapes
    assert(f({
        static_cast<int>(0xFFFFFFFF),
        static_cast<int>(0x00000000),
        static_cast<int>(0xFFFFFFFF),
        static_cast<int>(0x00000000),
    }) == 32);

    // Test case 10: Sparse grid with few land cells
    std::vector<int> sparse_grid(1000, 0);
    sparse_grid[0] = static_cast<int>(0x80000000);
    sparse_grid[999] = static_cast<int>(0x00000001);
    assert(f(sparse_grid) == 1);



    // Test case 11: Stress test with fully filled grid
    std::vector<int> full_grid(1000, static_cast<int>(0xFFFFFFFF));
    assert(f(full_grid) == 1000 * 32);
}

int main() {
    test_f();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}