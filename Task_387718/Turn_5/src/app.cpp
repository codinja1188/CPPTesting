#include "app.h"

#include <vector>
#include <algorithm>

int f(std::vector<int> a) {
  int n = a.size();
  if (n == 0) {
    return 0;
  }

  int max_landmass = 0;
  std::vector<int> visited(n, 0);


  auto is_valid = [&](int r, int c) {
      return r >= 0 && r < n && c >= 0 && c < 32;
  };

  auto is_land = [&](int r, int c) {
      return is_valid(r,c) && ( (a[r] >> (31-c)) & 1);
  };


  auto dfs = [&](auto& self, int r, int c, int& current_landmass) -> void {
      if(!is_valid(r,c) || !is_land(r,c)) return;


      if( (visited[r] >> (31-c)) & 1) return;

      visited[r] |= (1 << (31-c));

      current_landmass++;

      // Explore adjacent cells
      self(self, r + 1, c, current_landmass);
      self(self, r - 1, c, current_landmass);
      self(self, r, c + 1, current_landmass);
      self(self, r, c - 1, current_landmass);

  };


  for (int r = 0; r < n; ++r) {
      for(int c = 0; c < 32; ++c) {
          if(is_land(r,c) && !((visited[r] >> (31 -c)) & 1)) {
             int current_landmass = 0;
             dfs(dfs,r,c, current_landmass);
             max_landmass = std::max(max_landmass, current_landmass);
          }
      }
  }
  return max_landmass;
}