#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int ans = 0;
    vector<int> xd = {0,-1,0,1};
    vector<int> yd = {-1,0,1,0};

    bool dfs(vector<vector<int>>& grid, int i, int j){
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == -1) return false;
        if (grid[i][j] == 1) return true;
        else{
            bool a = true;
            grid[i][j] = 1;
            for (int d = 0; d < 4; d++) a &= dfs(grid, i+xd[d], j + yd[d]);
            grid[i][j] = (a)? 1 : -1;
            return a;
        }
        return false;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0 && dfs(grid, i, j)){
                    ans++;
                    // cout << i << ", " << j << endl;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    Solution S;
    cout << S.closedIsland(grid) << endl;
    return 0;
}