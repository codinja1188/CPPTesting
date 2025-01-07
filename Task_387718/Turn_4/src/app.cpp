#include "app.h"

#include <vector>
#include <queue>
#include <algorithm>

int f(std::vector<int> a) {
  if (a.empty()) {
    return 0;
  }

  int n = a.size();
  int max_landmass = 0;
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(32, false));

  auto is_valid = [&](int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < 32;
  };

  auto get_bit = [&](int r, int c) {
      return (a[r] >> (31 - c)) & 1;
  };
    
  auto bfs = [&](int start_r, int start_c) {
    int current_landmass = 0;
    std::queue<std::pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      current_landmass++;

      int dr[] = {-1, 1, 0, 0};
      int dc[] = {0, 0, -1, 1};

      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (is_valid(nr, nc) && !visited[nr][nc] && get_bit(nr, nc) == 1) {
          q.push({nr, nc});
          visited[nr][nc] = true;
        }
      }
    }
    return current_landmass;
  };

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < 32; ++c) {
      if (get_bit(r,c) == 1 && !visited[r][c]) {
        max_landmass = std::max(max_landmass, bfs(r, c));
      }
    }
  }

  return max_landmass;
}