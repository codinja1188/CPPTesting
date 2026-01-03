#include "app.h"
#include <iostream>

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void test() {
    // Test case 1: [2, 3, 4] -> GCD(2,3)=1, GCD(3,4)=1, already relatively prime
    std::vector<int> test1 = {2, 3, 4};
    std::cout << "Test 1: ";
    printVector(test1);
    std::cout << " -> ";
    auto result1 = g(test1);
    printVector(result1);
    std::cout << std::endl;
    
    // Test case 2: [2, 4, 3] -> GCD(2,4)=2, replace with LCM(2,4)=4 -> [4, 3]
    std::vector<int> test2 = {2, 4, 3};
    std::cout << "Test 2: ";
    printVector(test2);
    std::cout << " -> ";
    auto result2 = g(test2);
    printVector(result2);
    std::cout << std::endl;
    
    // Test case 3: [6, 10, 15] -> multiple steps needed
    std::vector<int> test3 = {6, 10, 15};
    std::cout << "Test 3: ";
    printVector(test3);
    std::cout << " -> ";
    auto result3 = g(test3);
    printVector(result3);
    std::cout << std::endl;
    
    // Test case 4: [12, 18, 24] -> all have common factors
    std::vector<int> test4 = {12, 18, 24};
    std::cout << "Test 4: ";
    printVector(test4);
    std::cout << " -> ";
    auto result4 = g(test4);
    printVector(result4);
    std::cout << std::endl;
    
    // Test case 5: Single element
    std::vector<int> test5 = {5};
    std::cout << "Test 5: ";
    printVector(test5);
    std::cout << " -> ";
    auto result5 = g(test5);
    printVector(result5);
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}
