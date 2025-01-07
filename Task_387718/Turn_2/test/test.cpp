#include "../src/app.h"

#include <iostream>
#include <vector>
#include <cassert>

// Include the function to be tested
// int f(std::vector<int> a); // Assuming f is defined in a separate file or included prior.

int main() {
  // Test case 1: Empty map
  assert(f({}) == 0);

  // Test case 2: Single land cell
  assert(f({1}) == 1);

    // Test case 3: Single row of land
    assert(f({static_cast<int>(0xFFFFFFFF)}) == 32);

  // Test case 4: Two separate land cells
    assert(f({0x00000001, 0x00000002}) == 1);

  // Test case 5: A larger land mass.
    assert(f({0x00000003, 0x00000003}) == 4);


  // Test case 6: Multiple disconnected land masses of different sizes.
    assert(f({0x00000001, 0x00000002, 0x00000010, 0x00000004, 0x00000008, 0x00000001}) == 1);


    // Test case 7: A square land mass
    assert(f({0x00000006, 0x00000006}) == 4);

    // Test case 8: Land mass with varying sizes in different rows.
     assert(f({0x00000003, 0x00000007, 0x00000003}) == 7);


  // Test case 9: A more complex land mass
    std::vector<int> complex_land = {
        0x0000001E,
        0x0000001E,
        0x0000001E,
        0x00000000,
        0x00000003,
    };
    std::cout << f(complex_land) << std::endl;
    assert(f(complex_land) == 15);

    std::vector<int> complex_land2 = {
        0x00000007,
        0x00000007,
		0x00000007,
        0x00000000,
        0x00000001,

    };

    assert(f(complex_land2) == 9);



    std::vector<int> complex_land3 = {static_cast<int>(
		0b10000000000000000000000000000001,
		0b01000000000000000000000000000010,
		0b00100000000000000000000000000100,
		0b00010000000000000000000000001000,
		0b00001000000000000000000000010000,
		0b00000100000000000000000000100000,
		0b00000010000000000000000001000000,
		0b00000001000000000000000010000000,
		0b00000000100000000000000100000000,
		0b00000000010000000000001000000000,
		0b00000000001000000000010000000000,
		0b00000000000100000000100000000000,
		0b00000000000010000001000000000000,
		0b00000000000001000010000000000000,
		0b00000000000000100100000000000000,
		0b00000000000000011000000000000000

    )};

	assert(f(complex_land3) == 2);

  std::cout << "All test cases passed!" << std::endl;

  return 0;
}