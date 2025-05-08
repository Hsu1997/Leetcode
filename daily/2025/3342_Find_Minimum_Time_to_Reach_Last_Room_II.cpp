#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    bool in_range(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        m = moveTime.size();
        n = moveTime[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        vector<int> dir = {0, 1, 0, -1, 0};
        priority_queue<pair<int, pair<int, pair<int,int>>>, vector<pair<int, pair<int, pair<int,int>>>>, greater<>> pq;
        pq.push({0, {0, {0, 0}}});
        while(!pq.empty()){
            auto [t, detail] = pq.top();
            auto [steps, pos] = detail;
            auto [x, y] = pos;
            pq.pop();
            if (dp[x][y][steps] != -1) continue;
            dp[x][y][steps] = t;
            for (int d = 0; d < 4; d++){
                int nx = x + dir[d];
                int ny = y + dir[d+1];
                if (!in_range(nx, ny) || dp[nx][ny][steps ^ 1] != -1) continue;
                int arrived_time = max(t, moveTime[nx][ny]) + steps + 1;
                pq.push({arrived_time, {steps ^ 1, {nx, ny}}});
            }
        }
        // for (auto i : dp){
        //     for (auto j : i){
        //         cout << j[0] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (auto i : dp){
        //     for (auto j : i){
        //         cout << j[1] << " ";
        //     }
        //     cout << endl;
        // }
        return min((dp[m-1][n-1][0] == -1)? INT_MAX : dp[m-1][n-1][0], (dp[m-1][n-1][1] == -1)? INT_MAX : dp[m-1][n-1][1]);
    }
};

int main(){
    vector<vector<int>> moveTime = {{0,4},{4,4}};
    // vector<vector<int>> moveTime = {{0,0,0,0},{0,0,0,0}};
    // vector<vector<int>> moveTime = {{0,1},{1,2}};
    Solution S;
    cout << S.minTimeToReach(moveTime) << endl;
    return 0;    
}