#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m;
    int n;
    bool in_field(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int to_index(int i, int j){
        return i * n + j;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        vector<int> dis = {0, 1, 0, -1, 0};
        vector<vector<int>> dp(m, vector<int>(n, -1));
        priority_queue<pair<int,int>> pq;
        dp[0][0] = health - grid[0][0];
        pq.push({dp[0][0], 0});
        while(!pq.empty()){
            auto [val, pos] = pq.top();
            pq.pop();
            int x = pos / n;
            int y = pos % n;
            // cout << "pos = " << pos << " = " << x << " " << y << endl;
            if (val < dp[x][y]) continue;
            for (int d = 0; d < 4; d++){
                int nx = x + dis[d];
                int ny = y + dis[d+1];
                if (!in_field(nx, ny)) continue;
                if (val - grid[nx][ny] > dp[nx][ny]){
                    dp[nx][ny] = val - grid[nx][ny];
                    pq.push({dp[nx][ny], to_index(nx, ny)});
                    // cout << "push " << to_index(nx, ny) << " = " << nx << " " << ny << endl;
                }
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[m-1][n-1] > 0;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;
    // vector<vector<int>> grid = {{0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0}};
    // int health = 3;
    // vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    // int health = 5;
    Solution S;
    cout << S.findSafeWalk(grid, health) << endl;
    return 0;
}