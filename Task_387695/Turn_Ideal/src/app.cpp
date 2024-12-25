#include "app.h"

#include <vector>
#include <numeric>

// int g(std::vector<int> a, std::vector<int> b) {
//     if (a.size() != b.size() || a.empty()) {
//         return 0;
//     }

//     int total_width = std::accumulate(a.begin(), a.end(), 0) - (a.size() - 1);
//     int total_height = std::accumulate(b.begin(), b.end(), 0) - (b.size() - 1);

//     std::vector<std::vector<int>> dp(total_height, std::vector<int>(total_width, 0));
//     dp[0][0] = 1;

//     int current_width = 0;
//     int current_height = 0;

//     for (size_t i = 0; i < a.size(); ++i) {
//         if (a[i] == 0 || b[i] == 0) continue;

//         for (int h = current_height; h < current_height + b[i]; ++h) {
//             for (int w = current_width; w < current_width + a[i]; ++w) {
//                 if (dp[h][w] == 0) continue;

//                 if (w + 1 < current_width + a[i]) {
//                     dp[h][w + 1] = (dp[h][w + 1] + dp[h][w]) % 256;
//                 }

//                 if (h + 1 < current_height + b[i]) {
//                     dp[h + 1][w] = (dp[h + 1][w] + dp[h][w]) % 256;
//                 }
//             }
//         }

//         current_width += a[i] - 1;
//         current_height += b[i] - 1;
//     }

//     return dp[total_height - 1][total_width - 1];
// }


// int g(std::vector<int> a, std::vector<int> b) {
//   const int MOD = 256;
//   int m = a.size();
//   if (m == 0) {
//     return 0;
//   }

//   // Calculate cumulative widths and heights
//   std::vector<int> cum_width(m + 1, 0);
//   std::vector<int> cum_height(m + 1, 0);
//   for (int i = 0; i < m; ++i) {
//     cum_width[i + 1] = cum_width[i] + a[i];
//     cum_height[i + 1] = cum_height[i] + b[i];
//   }

//   // Calculate total width and height of the grid
//   int total_width = cum_width[m];
//   int total_height = cum_height[m];

//   // Calculate number of paths using dynamic programming
//   std::vector<std::vector<int>> dp(total_height + 1, std::vector<int>(total_width + 1, 0));
//   dp[0][0] = 1;
//   for (int i = 0; i <= total_height; ++i) {
//     for (int j = 0; j <= total_width; ++j) {
//       if (i > 0) {
//         dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
//       }
//       if (j > 0) {
//         dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
//       }
//     }
//   }

//   return dp[total_height][total_width];
// }

#include <vector>
#include <numeric>

int g(std::vector<int> a, std::vector<int> b) {
  int total_width = std::accumulate(a.begin(), a.end(), 0);
  int total_height = std::accumulate(b.begin(), b.end(), 0);

  std::vector<std::vector<int>> dp(total_height + 1, std::vector<int>(total_width + 1, 0));
  dp[0][0] = 1;

  int current_width = 0;
  int current_height = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    for (int h = 0; h <= total_height; ++h) {
      for (int w = 0; w <= total_width; ++w) {
          if(dp[h][w] == 0) continue;
          if(w < current_width + a[i] && h < current_height + b[i])
          {
            if (w + 1 <= total_width && w + 1 <= current_width + a[i])
            {
              dp[h][w+1] = (dp[h][w+1] + dp[h][w]) % 256;
            }
            if (h + 1 <= total_height && h + 1 <= current_height + b[i] )
            {
              dp[h+1][w] = (dp[h+1][w] + dp[h][w]) % 256;
            }
          }
      }
    }
    current_width += a[i];
    current_height += b[i];
  }
for (auto& row : dp) {
    for (auto& cell : row) {
        std::cout << cell << " ";
    }
    std::cout << std::endl;
}

  return dp[total_height][total_width];
}