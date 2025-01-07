#include "app.h"

#include <vector>
#include <algorithm>

int f(std::vector<int> a) {
  if (a.empty()) {
    return 0;
  }

  int n = a.size();
  int max_area = 0;
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(32, false));

  auto is_valid = [&](int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < 32;
  };

  auto dfs = [&](auto& self, int r, int c, int& area) -> void {
    if (!is_valid(r, c) || visited[r][c] || !(a[r] & (1 << c))) {
      return;
    }
    visited[r][c] = true;
    area++;

    self(self, r + 1, c, area);
    self(self, r - 1, c, area);
    self(self, r, c + 1, area);
    self(self, r, c - 1, area);
  };


  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < 32; ++c) {
      if ((a[r] & (1 << c)) && !visited[r][c]) {
        int area = 0;
        dfs(dfs, r, c, area);
        max_area = std::max(max_area, area);
      }
    }
  }
  return max_area;
}