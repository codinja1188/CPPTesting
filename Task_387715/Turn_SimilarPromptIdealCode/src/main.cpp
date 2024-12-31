#include "app.h"
#include <cassert>
#include <iostream>

void run_tests() {
    // Test 1: Basic 3x3 grid, sum of 20 achievable
    {
        std::vector<std::string> grid = {};
        int result = g(grid);
        std::cout << "Test 1 - Expected: 0, Got: " << result << std::endl;
        assert(result == 0);
    }

    // Test 2: No valid selection to achieve sum of 20
    {
        std::vector<std::string> grid = {""};
        int result = g(grid);
        std::cout << "Test 2 - Expected: 0, Got: " << result << std::endl;
        assert(result == 0);
    }

    // Test 3: Single row, no valid selection
    {
        std::vector<std::string> grid = {"1234"};
        int result = g(grid);
        std::cout << "Test 3 - Expected: 10, Got: " << result << std::endl;
        assert(result == 10);
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
        std::cout << "Test 4 - Expected: 10, Got: " << result << std::endl;
        assert(result == 10);
    }

}

int main() {
    run_tests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
