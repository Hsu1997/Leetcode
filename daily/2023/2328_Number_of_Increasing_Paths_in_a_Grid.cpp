#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int m, n;
    vector<vector<int>> memo;

    int dp(vector<vector<int>>& grid, int i, int j){
        if (memo[i][j] != -1) return memo[i][j];
        vector<int> d = {0, 1, 0, -1, 0};
        long ans = 1;
        for (int k = 0; k < 4; k++){
            int x = i + d[k];
            int y = j + d[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > grid[i][j]){
                ans = (ans + dp(grid, x, y)) % mod;
            }
        }
        return memo[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        long ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans = (ans + dp(grid, i, j)) % mod;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,1},{3,4}};
    // vector<vector<int>> grid = {{1},{2}};
    Solution S;
    cout << S.countPaths(grid) << endl;
    return 0;
}