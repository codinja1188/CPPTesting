#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "app.h"

int main() {
    std::vector<int> image = {0};
    // Test Case 1: Simple case, single white pixel in a black grid
    std::string a = "RPSS";
    std::vector<int> result = g(a);
    std::cout << "size of result: " << result.size() << std::endl;  
    assert(result.size() == 2);
    assert(result[0] == 2);
    assert(result[1] == 3);



    std::cout << "All test cases passed!" << std::endl;

    return 0;
}