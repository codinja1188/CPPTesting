#include "../src/app.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> rockPaperScissorsTournament(string tournament) {
    int n = tournament.length();
    vector<pair<int, char>> players;
    for (int i = 0; i < n; ++i) {
        players.push_back({i, tournament[i]});
    }

    while (players.size() > 1) {
        vector<pair<int, char>> next_round;
        for (int i = 0; i < players.size(); i += 2) {
            char p1_move = players[i].second;
            char p2_move = players[i + 1].second;

            if (p1_move == p2_move) {
                next_round.push_back(players[i]);
                next_round.push_back(players[i + 1]);
            } else if ((p1_move == 'R' && p2_move == 'S') || (p1_move == 'S' && p2_move == 'P') || (p1_move == 'P' && p2_move == 'R')) {
                next_round.push_back(players[i]);
            } else {
                next_round.push_back(players[i + 1]);
            }
        }
        players = next_round;
    }

    vector<int> winners;
    for (const auto& p : players) {
        winners.push_back(p.first);
    }
    sort(winners.begin(), winners.end());
    return winners;
}

void testRockPaperScissorsTournament() {
    // Test case 1 (from the problem statement)
    string tournament1 = "RPSS";
    vector<int> expected1 = {2, 3};
    vector<int> result1 = rockPaperScissorsTournament(tournament1);
    assert(result1 == expected1);

    // Test case 2: Single player
    string tournament2 = "R";
    vector<int> expected2 = {0};
    vector<int> result2 = rockPaperScissorsTournament(tournament2);
    assert(result2 == expected2);

    // Test case 3: All same move
    string tournament3 = "RRRR";
    vector<int> expected3 = {0, 1, 2, 3};
    vector<int> result3 = rockPaperScissorsTournament(tournament3);
    assert(result3 == expected3);

    // Test case 4:  More complex example
    string tournament4 = "RPSPRSRP";
    vector<int> expected4 = {0,2,6};
    vector<int> result4 = rockPaperScissorsTournament(tournament4);
    assert(result4 == expected4);

    //Test case 5: Another complex example
    string tournament5 = "PSRPSRPP";
    vector<int> expected5 = {0};
    vector<int> result5 = rockPaperScissorsTournament(tournament5);
    assert(result5 == expected5);


    cout << "All test cases passed!" << endl;
}

int main() {
    testRockPaperScissorsTournament();
    return 0;
}