#include "app.h"

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

  return dp[total_height][total_width];
}
// Ideal Code for Original Prompt

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


