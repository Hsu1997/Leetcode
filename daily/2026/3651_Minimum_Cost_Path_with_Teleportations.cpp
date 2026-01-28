#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    void modify_walk(vector<vector<int>>& dp, vector<vector<int>>& grid){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    }
    void modify_teleport(vector<vector<int>>& dp, vector<vector<int>>& grid, vector<pair<int,int>>& order){
        int curr_min = dp[order[0].first][order[0].second];
        int ptr = 0;
        for (int i = 1; i < order.size(); i++){
            int x = order[i].first;
            int y = order[i].second;
            while(grid[order[ptr].first][order[ptr].second] != grid[x][y]){
                dp[order[ptr].first][order[ptr].second] = min(dp[order[ptr].first][order[ptr].second], curr_min);
                ptr++;
            }
            curr_min = min(curr_min, dp[x][y]);
        }
        while(ptr < order.size()){
            dp[order[ptr].first][order[ptr].second] = min(dp[order[ptr].first][order[ptr].second], curr_min);
            ptr++;
        }
        return;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        vector<pair<int,int>> order;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                order.push_back({i, j});
            }
        }
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b){
            return grid[a.first][a.second] > grid[b.first][b.second];
        };
        sort(order.begin(), order.end(), cmp);
        // for (auto i : order) cout << i.first << " " << i.second << endl;
        modify_walk(dp, grid);
        while(k--){
            modify_teleport(dp, grid, order);
            modify_walk(dp, grid);
        }
        return dp[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,3},{2,5,4},{4,3,5}};
    int k = 2;
    // vector<vector<int>> grid = {{1,2},{2,3},{3,4}};
    // int k = 1;
    // vector<vector<int>> grid = {{3,1},{10,4}};
    // int k = 7;
    // vector<vector<int>> grid = {{19,7,7,10,25,21},{34,25,16,7,19,19},{15,18,34,15,23,48}};
    // int k = 0;
    Solution S;
    cout << S.minCost(grid, k) << endl;
    return 0;
}