#include "app.h"


int g(std::vector<int> a, int b, int c) {
    if (c < 0 || c >= a.size() || b < 0 || b >= 32) {
        return 0;
    }

    int rows = a.size();
    std::queue<std::pair<int, int>> q;
    int start_color = (a[c] >> (31 - b)) & 1;

    if (start_color == 1) {
        int total_white = 0;
        for (int row : a) {
            total_white += std::bitset<32>(row).count();
        }
        return total_white;
    }

    q.push({b, c});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x < 0 || x >= 32 || y < 0 || y >= rows) {
            continue;
        }

        int current_color = (a[y] >> (31 - x)) & 1;
        if (current_color == 1) {
            continue;
        }

        a[y] |= (1 << (31 - x));

        q.push({x + 1, y});
        q.push({x - 1, y});
        q.push({x, y + 1});
        q.push({x, y - 1});
    }

    int total_white = 0;
    for (int row : a) {
        total_white += std::bitset<32>(row).count();
    }

    return total_white;
}
