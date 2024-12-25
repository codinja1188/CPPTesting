#include "app.h"

int g(std::vector<int> a, std::vector<int> b) {
    int width = std::accumulate(a.begin(), a.end(), 0);
    int height = std::accumulate(b.begin(), b.end(), 0);

    if (width == 0 || height == 0) {
        return 0;
    }

    std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
    dp[0][0] = 1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 256;
            }
            if (j > 0) {
               dp[i][j] = (dp[i][j] + dp[i][j-1]) % 256;
            }
        }
    }
    return dp[height - 1][width - 1];
}

