#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<int> d = {0, 1, 0, -1 ,0};
    bool in_range(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        while(!pq.empty()){
            auto [remove, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            if (x == m - 1 && y == n - 1) return remove;
            for (int dir = 0; dir < 4; dir++){
                int newx = x + d[dir];
                int newy = y + d[dir+1];
                if (!in_range(newx, newy) || remove + (grid[newx][newy] == 1) >= dp[newx][newy]) continue;
                dp[newx][newy] = remove + (grid[newx][newy] == 1);
                pq.push({dp[newx][newy], {newx, newy}});
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,1},{1,1,0},{1,1,0}};
    // vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    Solution S;
    cout << S.minimumObstacles(grid) << endl;
    return 0;
}