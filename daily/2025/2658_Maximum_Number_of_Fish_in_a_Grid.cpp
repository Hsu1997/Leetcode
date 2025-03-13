#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> que;
        int ans = 0;
        que.push({i, j});
        ans += grid[i][j];
        grid[i][j] = 0;
        vector<int> d = {0, 1, 0, -1, 0};
        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            for (int dir = 0; dir < 4; dir++){
                int nr = r + d[dir];
                int nc = c + d[dir+1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0){
                    ans += grid[nr][nc];
                    que.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    // vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
    // vector<vector<int>> grid = {{4},{5}};
    Solution S;
    cout << S.findMaxFish(grid) << endl;
    return 0;
}