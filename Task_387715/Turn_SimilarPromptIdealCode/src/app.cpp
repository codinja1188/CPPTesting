
#include "app.h"

#include <vector>
#include <string>
#include <algorithm>

// Function to calculate the maximum removable items
int g(std::vector<std::string> a) {
    if (a.empty() || a[0].empty()) {
        return 0;
    }

    int rows = a.size();
    int cols = a[0].size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    // Initialize top-left corner
    dp[0][0] = a[0][0] - '0';

    // Fill first row (can only move right)
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j - 1] + (a[0][j] - '0');
    }

    // Fill first column (can only move down)
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i - 1][0] + (a[i][0] - '0');
    }

    // Fill the rest of the dp table by choosing max of left or top
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = (a[i][j] - '0') + std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Return the value at the bottom-right corner of the dp table
    return dp[rows - 1][cols - 1];
}
