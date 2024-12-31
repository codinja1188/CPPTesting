
#include "app.h"



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <numeric>

int g(std::vector<std::string> a) {
    if (a.empty()) {
        return -1;
    }

    int rows = a.size();
    int cols = a[0].size();

    for (const auto& row : a) {
        if (row.size() != cols) {
            return -1;
        }
    }


    std::vector<std::pair<int, int>> cells;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
             cells.push_back({r, c});
        }
    }

    int min_compartments = INT_MAX;
    for (int i = 0; i < (1 << cells.size()); ++i) {
        int current_sum = 0;
        int current_compartments = 0;
        std::vector<std::pair<int, int>> selected_cells;

        for(int j = 0; j < cells.size(); j++){
            if((i >> j) & 1) {
                selected_cells.push_back(cells[j]);
            }
        }


        bool valid_selection = true;
        for (const auto& cell : selected_cells)
        {
             int r = cell.first;
             int c = cell.second;

            for (int k = 0; k < r; ++k) {
                bool found = false;
                 for(const auto& scell : selected_cells) {
                    if(scell.first == k && scell.second == c) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    valid_selection = false;
                    break;
                }
             }

            if(!valid_selection) break;


            for(int k = 0; k < c; ++k) {
                 bool found = false;
                  for(const auto& scell : selected_cells) {
                    if(scell.first == r && scell.second == k) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    valid_selection = false;
                    break;
                }
            }

            if(!valid_selection) break;
        }
        
        if (valid_selection)
        {

            for(const auto& cell : selected_cells) {
                current_sum += (a[cell.first][cell.second] - '0');
                current_compartments++;
            }


            if(current_sum == 20) {
                min_compartments = std::min(min_compartments, current_compartments);
            }
        }
    }



    if (min_compartments == INT_MAX) {
        return -1;
    }
    return min_compartments;
}