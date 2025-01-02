#include "app.h"

#include <vector>
#include <string>
#include <algorithm>

// Function to determine if move a beats move b
bool beats(char a, char b) {
    return (a == 'R' && b == 'S') || 
           (a == 'S' && b == 'P') || 
           (a == 'P' && b == 'R');
}

std::vector<int> g(std::string a) {
    int n = a.length();
    
    // Start with all players
    std::vector<std::vector<int>> curr_players(n);
    for (int i = 0; i < n; i++) {
        curr_players[i] = {i};
    }
    
    // Process each round
    while (n > 1) {
        std::vector<std::vector<int>> next_round;
        
        // Process pairs of players/groups
        for (int i = 0; i < n; i += 2) {
            std::vector<int> group1 = curr_players[i];
            std::vector<int> group2 = curr_players[i + 1];
            
            char move1 = a[group1[0]];  // All players in group1 play the same move
            char move2 = a[group2[0]];  // All players in group2 play the same move
            
            if (move1 == move2) {
                // Draw: combine both groups
                std::vector<int> combined;
                combined.insert(combined.end(), group1.begin(), group1.end());
                combined.insert(combined.end(), group2.begin(), group2.end());
                next_round.push_back(combined);
            } else if (beats(move1, move2)) {
                next_round.push_back(group1);
            } else {
                next_round.push_back(group2);
            }
        }
        
        curr_players = next_round;
        n = curr_players.size();
    }
    
    // Get the winning indices from the final group
    std::vector<int> result = curr_players[0];
    std::sort(result.begin(), result.end());
    return result;
}