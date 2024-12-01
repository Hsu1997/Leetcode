#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<int> dir = {0, 1, 0, -1, 0};
    bool in_range(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            auto [step, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            if (x == m-1 && y == n-1) return step;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (int d = 0; d < 4; d++){
                int nx = x + dir[d];
                int ny = y + dir[d+1];
                if (!in_range(nx, ny) || visited[nx][ny]) continue;
                int wait = ((grid[nx][ny] - step) % 2 == 0)? 1 : 0;
                int next_time = max(grid[nx][ny] + wait, step + 1);
                pq.push({next_time, {nx, ny}});
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    // vector<vector<int>> grid = {{0,2,4},{3,2,1},{1,0,4}};
    Solution S;
    cout << S.minimumTime(grid) << endl;
    return 0;
}