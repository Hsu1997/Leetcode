#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<int> x = {1,0,-1,0};
    vector<int> y = {0,-1,0,1};

    bool in_board(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++){
            if (in_board(i+x[k], j+y[k]) && grid[i+x[k]][j+y[k]] == '1'){
                // cout << i+x[k] << ", " << j+y[k] << endl;
                dfs(grid, i+x[k], j+y[k]);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    count++;
                    // cout << i << ", " << j << " is land" << endl;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};
    Solution S;
    cout << S.numIslands(grid) << endl;
    return 0;
}