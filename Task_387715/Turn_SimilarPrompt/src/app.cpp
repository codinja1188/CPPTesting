
#include "app.h"


int g(std::vector<std::string> a) {
  if (a.empty() || a[0].empty()) {
    return 0;
  }

  int rows = a.size();
  int cols = a[0].size();
  std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
  int max_removed = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      int current_capacity = a[i][j] - '0';
      int left_sum = (j > 0) ? dp[i][j - 1] : 0;
      int top_sum = (i > 0) ? dp[i - 1][j] : 0;
      int top_left_sum = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
      
      dp[i][j] = current_capacity;
      if (i > 0 || j > 0){
         dp[i][j] += std::max({left_sum, top_sum, top_left_sum});
      }
     
      max_removed = std::max(max_removed, dp[i][j]);
    }
  }
  
  return max_removed;
}