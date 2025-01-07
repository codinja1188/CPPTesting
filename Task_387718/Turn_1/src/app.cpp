#include "app.h"

#include <vector>
#include <queue>
#include <iostream> // for debugging
#include <stdexcept>

int g(std::vector<int> a, int b, int c) {
    if (a.empty()) return 0;
    if (b < 0 || b > 31 || c < 0 || c >= a.size()) {
        throw std::invalid_argument("Invalid starting coordinates.");
    }
     int rows = a.size();
    std::vector<int> image = a; // Create a copy to modify
    int targetColor = (image[c] >> (31 - b)) & 1; // Get starting pixel color
    int fillCount = 0;

    std::queue<std::pair<int, int>> q;
    q.push({b, c});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x < 0 || x > 31 || y < 0 || y >= rows) continue;

        int currentColor = (image[y] >> (31-x)) & 1;

        if(currentColor == targetColor) {
             if (currentColor == 1)
              {
                fillCount++;
              }
             image[y] ^= (1 << (31 - x)); // Flip the pixel

            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }
    }
     return fillCount;
}