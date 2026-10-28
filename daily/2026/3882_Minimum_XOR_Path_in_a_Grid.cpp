#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, 0)));
        int c = grid[0][0];
        int r = grid[0][0];
        dp[0][0][c] = true;
        for (int i = 1; i < m; i++){
            r ^= grid[i][0];
            dp[i][0][r] = true;
        }
        for (int j = 1; j < n; j++){
            c ^= grid[0][j];
            dp[0][j][c] = true;
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                for (int k = 0; k < 1024; k++){
                    int curr = grid[i][j];
                    if (dp[i-1][j][k]) dp[i][j][k ^ curr] = true;
                    if (dp[i][j-1][k]) dp[i][j][k ^ curr] = true;
                }
            }
        }
        for (int k = 0; k < 1024; k++) if (dp[m-1][n-1][k]) return k;
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2},{3,4}};
    // vector<vector<int>> grid = {{6,7},{5,8}};
    // vector<vector<int>> grid = {{2,7,5}};
    Solution S;
    cout << S.minCost(grid) << endl;
    return 0;
}