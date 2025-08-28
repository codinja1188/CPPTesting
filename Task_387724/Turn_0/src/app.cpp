#include "app.h"

std::vector<int> g(std::string a) {
  std::vector<int> current_winners;
  for (size_t i = 0; i < a.size(); ++i) {
    current_winners.push_back(static_cast<int>(i));
  }

  while (current_winners.size() > 1) {
    std::vector<int> next_winners;
    for (size_t i = 0; i < current_winners.size(); i += 2) {
        int p1_index = current_winners[i];
        int p2_index = current_winners[i+1];
        char p1_move = a[p1_index];
        char p2_move = a[p2_index];

        if (p1_move == p2_move) {
            next_winners.push_back(p1_index);
            next_winners.push_back(p2_index);
        } else if ((p1_move == 'R' && p2_move == 'S') ||
                   (p1_move == 'P' && p2_move == 'R') ||
                   (p1_move == 'S' && p2_move == 'P')) {
            next_winners.push_back(p1_index);
        } else {
            next_winners.push_back(p2_index);
        }
      
    }
    current_winners = next_winners;
  }
    
    std::sort(current_winners.begin(), current_winners.end());
    return current_winners;
}
