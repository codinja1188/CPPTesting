#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
#include "app.h"

using namespace std;

int numPaths(vector<int>& a, vector<int>& b) {
    if (a.empty() || b.empty() || a.size() != b.size()) {
        return 0;
    }

    int totalWidth = 0;
    int totalHeight = 0;
    for (int i = 0; i < a.size(); ++i) {
        totalWidth = max(totalWidth, a[i]);
        totalHeight += b[i];
    }

    vector<vector<int>> grid(totalHeight, vector<int>(totalWidth, 1)); 

    int currentHeight = 0;
    for(int i = 0; i < a.size(); ++i){
        for(int j = a[i]; j < totalWidth; ++j){
            for(int k = 0; k < b[i]; ++k){
                grid[currentHeight + k][j] = 0;
            }
        }
        currentHeight += b[i];
    }

    vector<vector<int>> dp(totalHeight, vector<int>(totalWidth, 0));
    dp[0][0] = 1;

    for (int i = 0; i < totalHeight; ++i) {
        for (int j = 0; j < totalWidth; ++j) {
            if (grid[i][j] == 0) continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 256;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 256;
        }
    }

    return dp[totalHeight - 1][totalWidth - 1];
}

int main() {
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{3, 5}, {2, 4}},
        {{1,2,3}, {3,2,1}},
        {{1}, {1}},
        {{}, {}},
        {{5}, {5}},
        {{2,2,2}, {2,2,2}},
        {{1, 3, 1}, {1,1,1}},
        {{1,1,1},{10,1,10}}
    };

    vector<int> expectedOutputs = {105, 60, 1, 0, 1, 20, 3, 20};

    for (int i = 0; i < testCases.size(); ++i) {
        int result = numPaths(testCases[i].first, testCases[i].second);
        cout << "Test case " << i + 1 << ": ";
        assert(result == expectedOutputs[i]);
        cout << "Passed" << endl;
    }

    cout << "All test cases passed!" << endl;
    return 0;
}