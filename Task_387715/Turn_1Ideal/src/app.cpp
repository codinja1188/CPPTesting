
#include "app.h"

#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

// Helper function to check if a cell (r, c) is valid and can be part of the current path
bool isValid(const std::vector<std::vector<int>>& grid, int r, int c, const std::vector<std::vector<bool>>& visited) {
    return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && !visited[r][c] && grid[r][c] > 0;
}

// BFS to collect connected compartments
void bfs(const std::vector<std::vector<int>>& grid, int r, int c, std::vector<int>& values, std::vector<std::vector<bool>>& visited) {
    std::queue<std::pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        values.push_back(grid[row][col]);

        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (isValid(grid, nr, nc, visited)) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

// Dynamic Programming - Subset Sum
int subset_sum(const std::vector<int>& values, int target) {
    int n = values.size();
    std::vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int v : values) {
        for (int t = target; t >= v; --t) {
            if (dp[t - v] != INT_MAX) {
                dp[t] = std::min(dp[t], dp[t - v] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

// Main function to compute minimum compartments summing to 20
int g(const std::vector<std::string> a) {
    if (a.empty() || std::any_of(a.begin(), a.end(), [&](const std::string& s){ return s.size() != a[0].size(); })) {
        return -1;
    }

    int rows = a.size();
    int cols = a[0].size();
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols));
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    int min_compartments = INT_MAX;

    // Convert input strings to integer grid
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            grid[r][c] = a[r][c] - '0';
        }
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] > 0 && !visited[r][c]) {
                std::vector<int> values;
                bfs(grid, r, c, values, visited);

                int compartments = subset_sum(values, 20);
                if (compartments != -1) {
                    min_compartments = std::min(min_compartments, compartments);
                }
            }
        }
    }

    return (min_compartments == INT_MAX) ? -1 : min_compartments;
}