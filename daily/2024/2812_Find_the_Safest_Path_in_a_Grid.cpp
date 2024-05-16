#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> safeness;
    vector<vector<int>> greatest_path;
    vector<int> pos_d = {0, 1, 0, -1, 0};
    bool in_range(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1]) return 0;
        queue<pair<pair<int,int>, int>> safe;
        safeness = vector(m, vector(n, INT_MAX));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]) safeness[i][j] = 0, safe.push({{i,j},0});
            }
        }
        while(!safe.empty()){
            auto [i, j] = safe.front().first;
            int dis = safe.front().second;
            safe.pop();
            for (int d = 0; d < 4; d++){
                if (in_range(i+pos_d[d], j+pos_d[d+1]) && safeness[i+pos_d[d]][j+pos_d[d+1]] > dis+1){
                    safeness[i+pos_d[d]][j+pos_d[d+1]] = dis+1;
                    safe.push({{i+pos_d[d], j+pos_d[d+1]}, dis+1});
                }
            }
        }
        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << safeness[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        queue<pair<int,int>> que;
        que.push({0,0});
        greatest_path = vector(m, vector(n, -1));
        greatest_path[0][0] = safeness[0][0];
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int d = 0; d < 4; d++){
                int new_x = x + pos_d[d];
                int new_y = y + pos_d[d+1];
                if (in_range(new_x, new_y) && min(greatest_path[x][y], safeness[new_x][new_y]) > greatest_path[new_x][new_y]){
                    greatest_path[new_x][new_y] = min(greatest_path[x][y], safeness[new_x][new_y]);
                    que.push({new_x, new_y});
                }
            }
        }
        return greatest_path[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
    // vector<vector<int>> grid = {{0,0,1},{0,0,0},{0,0,0}};
    // vector<vector<int>> grid = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
    Solution S;
    cout << S.maximumSafenessFactor(grid) << endl;
    return 0;
}