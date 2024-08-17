#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int row;
    int col;
    
    bool in_field(int i, int j){
        return i >= 0 && j >= 0 && i < row && j < col;
    }
    
    bool isConnect(vector<vector<int>>& grid){
        vector<int> d = {0, 1, 0, -1, 0};
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (que.empty() && grid[i][j] == 1){
                    visited[i][j] = true;
                    que.push({i, j});
                    break;
                }
            }
        }
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            for (int k = 0; k < 4; k++){
                int x = temp.first + d[k];
                int y = temp.second + d[k+1];
                if (in_field(x, y) && grid[x][y] == 1 && !visited[x][y]){
                    visited[x][y] = true;
                    que.push({x, y});
                }
            }
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1 && !visited[i][j]) return false;
            }
        }
        return true;
    }

    int minDays(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1) count++;
            }
        }
        if (count < 2) return count;
        if (!isConnect(grid)) return 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    grid[i][j] = 0;
                    if (!isConnect(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    // vector<vector<int>> grid = {{1,1}};
    // vector<vector<int>> grid = {{1,0,1,0}};
    // vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution S;
    cout << S.minDays(grid) << endl;
    return 0;
}