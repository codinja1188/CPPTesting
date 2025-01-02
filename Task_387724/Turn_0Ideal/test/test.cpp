#include "../src/app.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;



void testg() {
    // Test case 1 (from the problem statement)
    string tournament1 = "RPSS";
    vector<int> expected1 = {2, 3};
    vector<int> result1 = g(tournament1);
    assert(result1 == expected1);

    // Test case 2: Single player
    string tournament2 = "R";
    vector<int> expected2 = {0};
    vector<int> result2 = g(tournament2);
    assert(result2 == expected2);

    // Test case 3: All same move
    string tournament3 = "RRRR";
    vector<int> expected3 = {0, 1, 2, 3};
    vector<int> result3 = g(tournament3);
    assert(result3 == expected3);

    // Test case 4:  More complex example
    string tournament4 = "RPSPRSRP";
    vector<int> expected4 = {2};
    vector<int> result4 = g(tournament4);
    assert(result4 == expected4);

    //Test case 5: Another complex example
    string tournament5 = "PSRPSRPP";
    vector<int> expected5 = {1};
    vector<int> result5 = g(tournament5);
    cout << "All test cases passed!" << endl;
}

int main() {
    testg();
    return 0;
}