#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        if (grid[0][0] > 0) dp[0][0][0] = grid[0][0];
        else if (grid[0][0] < 0) dp[0][0][1] = -grid[0][0];
        else dp[0][0][0] = dp[0][0][1] = 0;
        for (int j = 1; j < n; j++){
            if (grid[0][j] > 0){
                if (dp[0][j-1][0] != -1) dp[0][j][0] = dp[0][j-1][0] * grid[0][j];
                if (dp[0][j-1][1] != -1) dp[0][j][1] = dp[0][j-1][1] * grid[0][j];
            }
            else if (grid[0][j] < 0){
                if (dp[0][j-1][0] != -1) dp[0][j][1] = dp[0][j-1][0] * -grid[0][j];
                if (dp[0][j-1][1] != -1) dp[0][j][0] = dp[0][j-1][1] * -grid[0][j];
            }
            else{
                dp[0][j][0] = 0;
                dp[0][j][1] = 0;
            }
        }
        for (int i = 1; i < m; i++){
            if (grid[i][0] > 0){
                if (dp[i-1][0][0] != -1) dp[i][0][0] = dp[i-1][0][0] * grid[i][0];
                if (dp[i-1][0][1] != -1) dp[i][0][1] = dp[i-1][0][1] * grid[i][0];
            }
            else if (grid[i][0] < 0){
                if (dp[i-1][0][0] != -1) dp[i][0][1] = dp[i-1][0][0] * -grid[i][0];
                if (dp[i-1][0][1] != -1) dp[i][0][0] = dp[i-1][0][1] * -grid[i][0];
            }
            else{
                dp[i][0][0] = 0;
                dp[i][0][1] = 0;
            }
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (grid[i][j] > 0){
                    if (max(dp[i-1][j][0], dp[i][j-1][0]) != -1) dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) * grid[i][j];
                    if (max(dp[i-1][j][1], dp[i][j-1][1]) != -1) dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) * grid[i][j];
                }
                else if (grid[i][j] < 0){
                    if (max(dp[i-1][j][1], dp[i][j-1][1]) != -1) dp[i][j][0] = max(dp[i-1][j][1], dp[i][j-1][1]) * -grid[i][j];
                    if (max(dp[i-1][j][0], dp[i][j-1][0]) != -1) dp[i][j][1] = max(dp[i-1][j][0], dp[i][j-1][0]) * -grid[i][j];
                }
                else{
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                }
            }
        }
        if (dp[m-1][n-1][0] == -1) return -1;
        return dp[m-1][n-1][0] % (long long)(1e9 + 7);
    }
};

int main(){
    vector<vector<int>> grid = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    // vector<vector<int>> grid = {{1,-2,1},{1,-2,1},{3,-4,1}};
    // vector<vector<int>> grid = {{1,3},{0,-4}};
    Solution S;
    cout << S.maxProductPath(grid) << endl;
    return 0;
}