#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    // int unipath = 0;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& obstacleGrid, int x, int y){
        // cout << x << "," << y << ":" << endl;
        if (x >= m || y >= n) return 0;
        if (dp[x][y] >= 0) return dp[x][y];

        if (obstacleGrid[x][y] == 1) dp[x][y] = 0;
        else{
            if (x == m-1 && y == n-1) dp[x][y] = 1;
            else dp[x][y] = dfs(obstacleGrid, x, y+1) + dfs(obstacleGrid, x+1, y);
        }
        return dp[x][y];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        dfs(obstacleGrid, 0, 0);

        // for (auto i : dp){
        //     for (auto j : i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        return dp[0][0];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    // vector<vector<int>> obstacleGrid = {{0,0},{0,1}};
    Solution S;
    cout << S.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}