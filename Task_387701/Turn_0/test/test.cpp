#include <iostream>
#include <cmath>
#include <cassert>

long long superfactorial(int n) {
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        long long fact = 1;
        for (int j = 1; j <= i; ++j) {
            fact *= j;
        }
        result *= fact;
    }
    return result;
}

// Function to count trailing zeros in a number
int countTrailingZeros(long long num) {
    int count = 0;
    while (num > 0 && num % 10 == 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to find the smallest n for the superfactorial to have at least |a| trailing zeros
int findMinN(int a) {
    int n = 0;
    int trailingZeros = 0;
    while (trailingZeros < std::abs(a)) {
        n++;
        trailingZeros = countTrailingZeros(superfactorial(n));
    }
    return n;
}


int main() {
    try {
        // Positive cases
        assert(findMinN(1) == 5);
        assert(findMinN(5) == 5);
        assert(findMinN(6) == 6);
        assert(findMinN(10) == 7);

        // Edge cases
        assert(findMinN(0) == 0); 

        // Negative cases (Exception handling)
        try {
            findMinN(-1);
            assert(false);  // Should not reach here
        } catch (const std::invalid_argument&) {
            assert(true);  // Exception expected
        }

        // Larger cases
        assert(findMinN(100) >= 12);

        // Direct superfactorial tests
        assert(countTrailingZeros(superfactorial(0)) == 0);
        assert(countTrailingZeros(superfactorial(1)) == 0);
        assert(countTrailingZeros(superfactorial(2)) == 0);
        assert(countTrailingZeros(superfactorial(3)) == 0);
        assert(countTrailingZeros(superfactorial(4)) == 1);
        assert(countTrailingZeros(superfactorial(5)) == 5);

        std::cout << "All test cases passed!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }

    return 0;
}