
#include "app.h"

int g(std::vector<std::string> a) {
  int rows = a.size();
  if (rows == 0) return INT_MAX;
  int cols = a[0].size();
  if (cols == 0) return INT_MAX;

  int min_compartments = INT_MAX;

  for (int i = 0; i < (1 << (rows * cols)); ++i) {
    int current_sum = 0;
    int current_compartments = 0;
    std::vector<std::pair<int, int>> selected_compartments;

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if ((i >> (r * cols + c)) & 1) {
          selected_compartments.push_back({r, c});
          current_sum += (a[r][c] - '0');
          current_compartments++;
        }
      }
    }
      
    if (current_sum == 20) {
      bool valid_selection = true;
      for(const auto& comp : selected_compartments) {
        int r = comp.first;
        int c = comp.second;
        if(r > 0) {
          bool above_selected = false;
          for(const auto& other_comp : selected_compartments){
            if(other_comp.first == r -1 && other_comp.second == c){
              above_selected = true;
              break;
            }
          }
          if(!above_selected){
            valid_selection = false;
            break;
          }
        }
        if(c > 0) {
          bool left_selected = false;
            for(const auto& other_comp : selected_compartments){
            if(other_comp.first == r && other_comp.second == c-1){
                left_selected = true;
                break;
            }
          }
            if(!left_selected){
                valid_selection = false;
                break;
            }
        }

      }

      if (valid_selection) {
        min_compartments = std::min(min_compartments, current_compartments);
      }
    }
  }
  return min_compartments == INT_MAX ? -1 : min_compartments;
}
