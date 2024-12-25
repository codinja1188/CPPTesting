#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
#include "app.h"

using namespace std;

// Assume the g function is defined as above

int g(std::vector<int> a, std::vector<int> b);

void test_g() {
    // Test case 1: Example from problem description
    assert(g({3, 5}, {2, 4}) == 105);

    // Test case 2: Single rectangle
    assert(g({3}, {2}) == 10);

    // Test case 3: Multiple rectangles with small dimensions
    assert(g({1, 1, 1}, {1, 1, 1}) == 20);

    // Test case 4: Rectangles with one dimension equal to 1
    assert(g({5, 1}, {1, 3}) == 15);

    // Test case 5:  Rectangles with one dimension equal to 1
    assert(g({1, 5}, {3, 1}) == 15);

     // Test case 6:  zero height
     assert(g({1, 5}, {0, 1}) == 0);

    // Test case 7: zero width
    assert(g({0, 5}, {1, 1}) == 0);


    // Test case 8: Large numbers to check overflow handling (mod 256)
    assert(g({10,10}, {10,10}) == 120);
  
    // Test case 9: Single big rectangle
    assert(g({10}, {10}) == 100 );

     // Test case 10
    assert(g({1,1}, {1,1}) == 6);
}

int main() {
  test_g();
  return 0;
}