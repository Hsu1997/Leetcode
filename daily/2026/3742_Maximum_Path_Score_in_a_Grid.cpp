#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 2, -1)));
        int c = (grid[0][0] > 0)? 1 : 0;
        int s = grid[0][0];
        dp[0][0][c] = s;
        for (int j = 1; j < n; j++){
            if (grid[0][j] > 0) c++, s += grid[0][j];
            if (c > k) break;
            dp[0][j][c] = s;
        }
        c = (grid[0][0] > 0)? 1 : 0;
        s = grid[0][0];
        for (int i = 1; i < m; i++){
            if (grid[i][0] > 0) c++, s += grid[i][0];
            if (c > k) break;
            dp[i][0][c] = s;
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                int curr = grid[i][j];
                if (curr == 0) dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]);
                for (int t = 1; t <= k; t++){
                    if (dp[i-1][j][t - (curr > 0)] != -1) dp[i][j][t] = max(dp[i][j][t], dp[i-1][j][t - (curr > 0)] + curr);
                    if (dp[i][j-1][t - (curr > 0)] != -1) dp[i][j][t] = max(dp[i][j][t], dp[i][j-1][t - (curr > 0)] + curr);
                    // dp[i][j][t] = max(dp[i-1][j][t - (curr > 0)], dp[i][j-1][t - (curr > 0)]) + curr;
                }
            }
        }
        int ans = -1;
        for (int t = 0; t <= k; t++) ans = max(ans, dp[m-1][n-1][t]);
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1},{2,0}};
    int k = 1;
    // vector<vector<int>> grid = {{0,1},{1,2}};
    // int k = 1;
    // vector<vector<int>> grid = {{0, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
    // int k = 5;
    Solution S;
    cout << S.maxPathScore(grid, k) << endl;
    return 0;
}