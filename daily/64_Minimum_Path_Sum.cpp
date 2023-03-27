#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp = grid[0];
        for (int j = 1; j < n; j++) dp[j] += dp[j-1];
        for (int i = 1; i < m; i++){
            dp[0] += grid[i][0];
            // cout << dp[0] << " ";
            for (int j = 1; j < n; j++){
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
                // cout << dp[j] << " ";
            }
            // cout << endl;
        }
        return dp[n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution S;
    cout << S.minPathSum(grid) << endl;
    return 0;
}