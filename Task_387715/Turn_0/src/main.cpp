#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Declaration of the function to be tested
int g(std::vector<std::string> a);

void run_tests() {
    // Test 1: Basic 3x3 grid, sum of 20 achievable
    {
        std::vector<std::string> grid = {
            "442",
            "442",
            "422"
        };
        int result = g(grid);
        std::cout << "Test 1 - Expected: 5, Got: " << result << std::endl;
        assert(result == 5);
    }

    // Test 2: No valid selection to achieve sum of 20
    {
        std::vector<std::string> grid = {
            "111",
            "111",
            "111"
        };
        int result = g(grid);
        std::cout << "Test 2 - Expected: -1, Got: " << result << std::endl;
        assert(result == -1);
    }

    // Test 3: Single row, no valid selection
    {
        std::vector<std::string> grid = {"1234"};
        int result = g(grid);
        std::cout << "Test 3 - Expected: -1, Got: " << result << std::endl;
        assert(result == -1);
    }

    // Test 4: Single column, no valid selection
    {
        std::vector<std::string> grid = {
            "1",
            "2",
            "3",
            "4"
        };
        int result = g(grid);
        std::cout << "Test 4 - Expected: -1, Got: " << result << std::endl;
        assert(result == -1);
    }

    // Test 5: Grid with sum greater than 20, but no valid compartments
    {
        std::vector<std::string> grid = {
            "99",
            "99"
        };
        int result = g(grid);
        std::cout << "Test 5 - Expected: -1, Got: " << result << std::endl;
        assert(result == -1);
    }
}

int main() {
    run_tests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
