#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> xd = {0,1,0,-1};
        vector<int> yd = {1,0,-1,0};
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        que.push({0,0});
        while(!que.empty()){
            auto [row,col] = que.front();
            int temp = dp[row][col];
            que.pop();
            for (int i = 0; i < 4; i++){
                int new_row = row + xd[i];
                int new_col = col + yd[i];
                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n){
                    int path = max(dp[row][col], abs(heights[new_row][new_col] - heights[row][col]));
                    if (path < dp[new_row][new_col]){
                        que.push({new_row, new_col});
                        dp[new_row][new_col] = path;
                    }
                }

            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp.back().back();
    }
};

int main(){
    // vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    // vector<vector<int>> heights = {{1,2,3},{3,8,4},{5,3,5}};
    // vector<vector<int>> heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    vector<vector<int>> heights = {{10,8},{10,8},{1,2},{10,3},{1,3},{6,3},{5,2}};
    Solution S;
    cout << S.minimumEffortPath(heights) << endl;
    return 0;
}