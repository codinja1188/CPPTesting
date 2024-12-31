#include "../src/app.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Test cases
    vector<pair<vector<string>, int>> testCases = {
        {{"442222222", "442222222", "422222212", "222222122"}, 5},
        {{"99999", "00000"}, 2},
        {{"55555"}, 4},
        {{"1111111111"},10},
        {{"2222222222"}, 5},
        {{"00000", "00000"}, -1},
        {{"12345", "67890"}, 3},

    };

    for (int i = 0; i < testCases.size(); ++i) {
        int result = g(testCases[i].first);
        if (result == testCases[i].second) {
            cout << "Test case " << i + 1 << " passed." << endl;
        } else {
            cout << "Test case " << i + 1 << " failed. Expected: " << testCases[i].second << ", Got: " << result << endl;
        }
    }

    return 0;
}