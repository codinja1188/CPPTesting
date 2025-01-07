#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Declaration of the function to be tested
int g(std::vector<int> a, int b, int c);

int main() {
    std::vector<int> image = {0};
    // Test Case 1: Simple case, single white pixel in a black grid 
    assert(g(image, 0, 0) == 0);

    image = {{00000000000000000000000000000000},
             {00000000000000000000000000000000},
             {00000000000000000000000000000000}
            };
    // Test Case 2: Entire grid is white
    assert(g(image, 0, 0) == 0);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}