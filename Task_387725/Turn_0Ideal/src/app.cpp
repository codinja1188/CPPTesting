// #include "app.h"

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <tuple>
// #include <unordered_set>
// #include <set>

// using namespace std;

// // Hash function for complex tuple states
// struct StateHash {
//     size_t operator()(const tuple<int, int, int, set<pair<int, int>>>& state) const {
//         auto [r, c, k, doors] = state;
//         size_t h1 = hash<int>()(r);
//         size_t h2 = hash<int>()(c);
//         size_t h3 = hash<int>()(k);
//         size_t h4 = 0;
//         for (const auto& d : doors) {
//             h4 ^= hash<int>()(d.first) ^ hash<int>()(d.second);
//         }
//         return h1 ^ h2 ^ h3 ^ h4;
//     }
// };

// // Dungeon traversal function
// int g(vector<string> a) {
//     int rows = a.size();
//     if (rows == 0) return -1;  // Empty dungeon check
//     int cols = a[0].size();
    
//     int start_row = -1, start_col = -1;

//     // Locate entrance (%)
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             if (a[i][j] == '%') {
//                 start_row = i;
//                 start_col = j;
//                 break;
//             }
//         }
//     }
    
//     if (start_row == -1) return -1;  // No entrance found

//     queue<tuple<int, int, int, set<pair<int, int>>>> q;
//     unordered_set<tuple<int, int, int, set<pair<int, int>>>, StateHash> visited;

//     q.push({start_row, start_col, 0, {}});  // row, col, distance, keys_collected, doors_opened

//     while (!q.empty()) {
//         auto [r, c, dist, doors_opened] = q.front();
//         q.pop();

//         // Mark state as visited
//         auto state = make_tuple(r, c, doors_opened.size(), doors_opened);
//         if (visited.count(state)) continue;
//         visited.insert(state);

//         // Check if we reached the big key
//         if (a[r][c] == 'T') return dist;

//         int dr[] = {-1, 1, 0, 0};
//         int dc[] = {0, 0, -1, 1};

//         // Explore 4 possible directions
//         for (int i = 0; i < 4; ++i) {
//             int nr = r + dr[i];
//             int nc = c + dc[i];

//             if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && a[nr][nc] != '#') {
//                 set<pair<int, int>> new_doors = doors_opened;

//                 if (a[nr][nc] == 't') {
//                     // Collect small key
//                     new_doors.insert({nr, nc});
//                     q.push({nr, nc, dist + 1, new_doors});
//                 } 
//                 else if (a[nr][nc] == '+') {
//                     // Try to open the door if we have keys
//                     if (!new_doors.empty()) {
//                         new_doors.erase(new_doors.begin());  // Consume one key
//                         q.push({nr, nc, dist + 1, new_doors});
//                     }
//                 } 
//                 else {
//                     // Move to regular floor or already opened path
//                     q.push({nr, nc, dist + 1, new_doors});
//                 }
//             }
//         }
//     }

//     return -1;  // No path to the big key
// }


#include "app.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <set>

using namespace std;

struct State {
    int row, col;
    int keys;
    int distance;
    set<pair<int, int>> opened_doors;
    set<pair<int, int>> collected_keys;
    
    bool operator==(const State& other) const {
        return row == other.row && 
               col == other.col && 
               keys == other.keys && 
               opened_doors == other.opened_doors &&
               collected_keys == other.collected_keys;
    }
};

struct StateHash {
    size_t operator()(const State& state) const {
        size_t h1 = hash<int>()(state.row);
        size_t h2 = hash<int>()(state.col);
        size_t h3 = hash<int>()(state.keys);
        size_t h4 = 0;
        for (const auto& door : state.opened_doors) {
            h4 ^= hash<int>()(door.first) ^ (hash<int>()(door.second) << 1);
        }
        size_t h5 = 0;
        for (const auto& key : state.collected_keys) {
            h5 ^= hash<int>()(key.first) ^ (hash<int>()(key.second) << 1);
        }
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ h4 ^ h5;
    }
};

int g(vector<string> a) {
    int rows = a.size();
    if (rows == 0) return -1;
    int cols = a[0].size();
    
    // Find starting position
    int start_row = -1, start_col = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] == '%') {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row != -1) break;
    }
    
    if (start_row == -1) return -1;

    queue<State> q;
    unordered_set<State, StateHash> visited;
    
    // Initialize starting state
    State initial_state = {
        start_row, 
        start_col, 
        0,        // keys
        0,        // distance
        {},       // opened_doors
        {}        // collected_keys
    };
    q.push(initial_state);

    // All possible directions
    const int dr[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
    const int dc[] = {0, 0, -1, 1};

    int min_dist = -1;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Found target
        if (a[current.row][current.col] == 'T') {
            if (min_dist == -1 || current.distance < min_dist) {
                min_dist = current.distance;
            }
            continue;
        }

        // Skip if state already visited
        if (visited.count(current)) continue;
        visited.insert(current);

        // Try all directions
        for (int i = 0; i < 4; ++i) {
            int new_row = current.row + dr[i];
            int new_col = current.col + dc[i];

            // Check boundaries and walls
            if (new_row < 0 || new_row >= rows || 
                new_col < 0 || new_col >= cols || 
                a[new_row][new_col] == '#') {
                continue;
            }

            State next_state = current;
            next_state.row = new_row;
            next_state.col = new_col;
            next_state.distance = current.distance + 1;

            pair<int, int> pos = {new_row, new_col};
            char cell = a[new_row][new_col];

            if (cell == 't' && current.collected_keys.count(pos) == 0) {
                // Collect new key
                next_state.keys++;
                next_state.collected_keys.insert(pos);
                q.push(next_state);
            }
            else if (cell == '+') {
                if (next_state.opened_doors.count(pos)) {
                    // Door already opened
                    q.push(next_state);
                }
                else if (next_state.keys > 0) {
                    // Open new door with a key
                    next_state.keys--;
                    next_state.opened_doors.insert(pos);
                    q.push(next_state);
                }
                // If we don't have keys, we can't proceed through this door
            }
            else {
                // Regular floor, entrance, or target
                q.push(next_state);
            }
        }
    }

    return min_dist;
}