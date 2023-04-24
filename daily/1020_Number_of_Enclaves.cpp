#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int land = 0;
    vector<int> xd = {0,-1,0,1};
    vector<int> yd = {-1,0,1,0};

    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        land--;
        for (int d = 0; d < 4; d++){
            dfs(grid, i + xd[d], j + yd[d]);
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) land++;
            }
        }
        for (int i = 0; i < m; i++){
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }
        for (int j = 0; j < n; j++){
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }
        return land;
    }
};

int main(){
    // vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    Solution S;
    cout << S.numEnclaves(grid) << endl;
    return 0;
}