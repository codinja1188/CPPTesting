#include "app.h"

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

// Function to get the bit value at position (r, c)
inline bool get_bit(int r, int c, const std::vector<int>& a) {
    return (a[r] >> (31 - c)) & 1;
}

// Function to set the bit value at position (r, c) to 0
inline void clear_bit(int r, int c, std::vector<int>& visited) {
    visited[r] |= (1 << (31 - c));
}

// Function to check if the bit at position (r, c) is visited
inline bool is_visited(int r, int c, const std::vector<int>& visited) {
    return (visited[r] >> (31 - c)) & 1;
}

int f(std::vector<int> a) {
    if (a.empty()) {
        return 0;
    }

    int n = a.size();
    int max_landmass = 0;
    std::vector<int> visited(n, 0);

    auto is_valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < 32;
    };

    auto bfs = [&](int start_r, int start_c) {
        int current_landmass = 0;
        std::queue<std::pair<int, int>> q;
        q.push({start_r, start_c});
        clear_bit(start_r, start_c, visited);

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

                if (is_valid(nr, nc) && !is_visited(nr, nc, visited) && get_bit(nr, nc, a) == 1) {
                    q.push({nr, nc});
                    clear_bit(nr, nc, visited);
                }
            }
        }
        return current_landmass;
    };

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < 32; ++c) {
            if (get_bit(r, c, a) == 1 && !is_visited(r, c, visited)) {
                int landmass_size = bfs(r, c);
                max_landmass = std::max(max_landmass, landmass_size);
            }
        }
    }

    return max_landmass;
}