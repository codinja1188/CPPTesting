#include "app.h"

int g(std::vector<int> a, int b, int c) {
  if (c < 0 || c >= a.size() || b < 0 || b >= 32) {
    return 0;
  }

  int rows = a.size();
  std::vector<int> filled = a;
  std::queue<std::pair<int, int>> q;
  q.push({b, c});
  int white_pixels = 0;


  int start_color = (a[c] >> (31 - b)) & 1;

  if(start_color == 1){
      return 0;
  }

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (x < 0 || x >= 32 || y < 0 || y >= rows) {
      continue;
    }


    int current_color = (filled[y] >> (31 - x)) & 1;

    if (current_color == 1) {
      continue;
    }


    filled[y] |= (1 << (31 - x));
    white_pixels++;

    q.push({x + 1, y});
    q.push({x - 1, y});
    q.push({x, y + 1});
    q.push({x, y - 1});
  }

    int total_white = 0;
    for(int row : filled){
        for(int i=0; i < 32; ++i){
            if((row >> (31 - i)) & 1){
                total_white++;
            }
        }
    }
    
    return total_white;
}
