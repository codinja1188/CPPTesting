#include "../src/app.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

int g(std::vector<std::string> a);

void test_case(const std::vector<std::string>& grid, int expected) {
    int result = g(grid);
    if (result != expected) {
        std::cerr << "Test failed for grid:\n";
        for (const auto& row : grid) {
            std::cerr << row << std::endl;
        }
        std::cerr << "Expected: " << expected << ", Got: " << result << std::endl;
        exit(1);
    }
}

int main() {
    test_case({"442222222",
               "442222222",
               "422222212",
               "222222122"}, 5);

    test_case({"111111111",
               "111111111",
               "111111111",
               "111111111"}, 20);

    test_case({"5555",
               "5551",
               "5511",
               "1111"}, 4);

    test_case({"123", "45"}, -1);

    test_case({}, -1);

    test_case({"000", "000", "000"}, -1);

    test_case({"1111111111",
               "1111111111",
               "2222222222",
               "2222222222"}, 10);

    test_case({"0000",
               "0000",
               "0000",
               "0002"}, -1);

    test_case({"5555",
               "5111",
               "1111",
               "1111"}, 4);

    test_case({"11111111111111111111"}, 20);

    test_case({"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}, 20);

    test_case({"1111111121",
               "1111111121",
               "1111111122",
               "1111111122",
               "1111111121"}, 13);

    test_case({"0000", "0000", "0020", "0000"}, -1);

    test_case({"111222111",
               "222222222",
               "111222111"}, 10);

    test_case({"111022111",
               "220222022",
               "111022111"}, 11);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}