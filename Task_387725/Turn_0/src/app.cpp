#include "app.h"



using namespace std;

int g(std::vector<std::string> a) {
    int rows = a.size();
    int cols = a[0].size();
    int start_row, start_col;
    vector <pair <int, int> > key_positions;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] == '%') {
                start_row = i;
                start_col = j;
            } else if (a[i][j] == 't') {
                key_positions.push_back({i, j});
            }
        }
    }

    queue<tuple<int, int, int, int, vector<pair<int,int>>>> q;
    q.push({start_row, start_col, 0, 0, {}}); // row, col, dist, keys_collected, doors_opened
    vector<tuple<int,int, int, vector<pair<int,int>>>> visited;

    while (!q.empty()) {
        int r, c, dist, keys_collected;
        vector<pair<int,int>> doors_opened;
        tie(r, c, dist, keys_collected, doors_opened) = q.front();
        q.pop();

        if (find(visited.begin(), visited.end(), make_tuple(r, c, keys_collected, doors_opened)) != visited.end()) {
            continue;
        }

        visited.push_back(make_tuple(r, c, keys_collected, doors_opened));

        if (a[r][c] == 'T') {
            return dist;
        }


        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && a[nr][nc] != '#') {
                int new_keys = keys_collected;
                vector<pair<int,int>> new_doors = doors_opened;
                if(a[nr][nc] == 't'){
                   bool key_already_collected = false;
                    for(const auto& kp : doors_opened){
                        if(kp.first == nr && kp.second == nc){
                            key_already_collected = true;
                            break;
                        }
                    }
                  if(!key_already_collected){
                      new_keys++;
                       new_doors.push_back({nr,nc});
                  }
                }
                else if (a[nr][nc] == '+') {

                    if (new_keys > 0 ) {
                        bool door_already_opened = false;
                        for(const auto& dp : doors_opened){
                            if(dp.first == nr && dp.second == nc){
                                door_already_opened = true;
                                break;
                            }
                        }
                       if(!door_already_opened){
                         new_keys--;
                         new_doors.push_back({nr,nc});
                       }

                    
                     q.push({nr, nc, dist + 1, new_keys, new_doors});
                    }
                   continue;
                }


                q.push({nr, nc, dist + 1, new_keys, new_doors});

            }
        }
    }
    return -1;
}
