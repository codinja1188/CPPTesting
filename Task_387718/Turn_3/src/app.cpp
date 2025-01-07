#include "app.h"

#include <vector>
#include <algorithm>

int f(std::vector<int> a) {
    int n = a.size();
    if (n == 0) return 0;
    std::vector<std::vector<bool>> grid(n, std::vector<bool>(32, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            grid[i][j] = (a[i] >> (31 - j)) & 1;
        }
    }

    int max_landmass = 0;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(32, false));

    auto dfs = [&](auto& self, int r, int c, int& current_landmass) -> void {
        if (r < 0 || r >= n || c < 0 || c >= 32 || visited[r][c] || !grid[r][c]) {
            return;
        }
        visited[r][c] = true;
        current_landmass++;

        self(self, r + 1, c, current_landmass);
        self(self, r - 1, c, current_landmass);
        self(self, r, c + 1, current_landmass);
        self(self, r, c - 1, current_landmass);
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (grid[i][j] && !visited[i][j]) {
                int current_landmass = 0;
                dfs(dfs, i, j, current_landmass);
                max_landmass = std::max(max_landmass, current_landmass);
            }
        }
    }

    return max_landmass;
}