#include "app.h"

#include <string>
#include <algorithm>
#include <iostream>

#include <string>
#include <exception>
#include <vector>


// Count trailing zeros in n!
long long countTrailingZeros(long long n) {
    long long count = 0;
    for (long long i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    return count;
}

// Compute smallest n such that superfactorial of n has at least target_zeros trailing zeros
int g(std::string a) {
        long long target_zeros = std::stoll(a);
        if (target_zeros < 0) return -1;
        if (target_zeros == 0) return 0;

        long long left = 0;
        long long right = 5 * target_zeros;  // Tighter upper bound based on zeros growth
        std::vector<long long> factorial_zeros(right + 1, 0);

        // Precompute trailing zeros for factorials up to right
        for (long long i = 1; i <= right; i++) {
            factorial_zeros[i] = factorial_zeros[i - 1] + countTrailingZeros(i);
        }

        // Binary search for smallest n
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long current_zeros = factorial_zeros[mid];
            //std::cout << "mid: " << mid << " current_zeros: " << current_zeros << std::endl;
            if (current_zeros >= target_zeros) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //std::cout << "left: " << left << std::endl;
        return static_cast<int>(left);
}

