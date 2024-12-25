#include "app.h"

int g(std::string a) {
  long long target_zeros = std::stoll(a);
  if (target_zeros == 0) {
    return 0;
  }

  long long low = 0;
  long long high = 1e6; // Adjust as needed based on problem constraints

  long long ans = -1;

  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long current_zeros = 0;
    for (long long i = 1; i <= mid; ++i) {
      long long temp = i;
      long long power_of_5 = 0;
      while (temp > 0) {
        power_of_5 += temp / 5;
        temp /= 5;
      }
      current_zeros += power_of_5;
    }


    if (current_zeros >= target_zeros) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
    if (ans == -1) {
        return -1; // This should not happen given the bounds in the problem description.
    }
  return static_cast<int>(ans);
}