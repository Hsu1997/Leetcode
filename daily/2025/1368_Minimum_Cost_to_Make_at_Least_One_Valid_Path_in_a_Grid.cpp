#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_range(int i, int j, int m, int n){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto [len, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            if (visited[i][j]) continue;
            visited[i][j] = true;
            if (i == m - 1 && j == n - 1) return len;
            for (int d = 0; d < 4; d++){
                int r = i + dir[d].first;
                int c = j + dir[d].second;
                if (!in_range(r, c, m, n)) continue;
                int new_len = len + ((grid[i][j] - 1 == d)? 0 : 1);
                if (new_len < dist[r][c]){
                    dist[r][c] = new_len;
                    pq.push({new_len, {r, c}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    // vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
    // vector<vector<int>> grid = {{1,2},{4,3}};
    Solution S;
    cout << S.minCost(grid) << endl;
    return 0;
}