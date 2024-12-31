#include "../src/app.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

int g(std::vector<std::string> a);

void test_case(const std::vector<std::string>& grid, int expected) {
    int result = g(grid);
    assert(result == expected);
}

int main() {

    // Test Case 1: Valid grid with exact solution
    test_case({"442222222",
               "442222222",
               "422222212",
               "222222122"}, 5);

    // Test Case 2: Grid with no possible combination summing to 20
     test_case({"111111111",
               "111111111",
               "111111111",
               "111111111"}, -1);

    // Test Case 3: Grid with varying values and a solution.
    test_case({"5555",
               "5551",
               "5511",
                "1111"}, 4);

    // Test Case 4: Invalid grid with inconsistent row lengths.
    test_case({"123", "45"}, -1);

    // Test Case 5: Empty grid.
    test_case({}, -1);

     // Test Case 6: Grid with all zeros.
    test_case({"000", "000", "000"}, -1);

     // Test Case 7: Larger grid with exact solution
     test_case({"1111111111",
               "1111111111",
               "2222222222",
                "2222222222"}, 10);

    // Test Case 8: Grid with a solution at the corner.
      test_case({"0000",
                  "0000",
                 "0000",
                 "0002"}, -1);

    // Test Case 9: Grid with another exact solution.
      test_case({"5555",
                 "5111",
                 "1111",
                 "1111"}, 6);
    
    // Test Case 10: Single row grid
    test_case({"11111111111111111111"}, -1);

    // Test Case 11: Single column grid
    test_case({"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}, -1);

    // Test Case 12: Large Grid with only 1's and 2's and an answer
    test_case({"1111111121",
                "1111111121",
                "1111111122",
                "1111111122",
                "1111111121"}, 10);


     std::cout << "All test cases passed!" << std::endl;

    return 0;
}