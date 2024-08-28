#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool in_range(int i, int j, int m, int n) {return i >= 0 && i < m && j >= 0 && j < n;}

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j, int m, int n){
        bool ans = true;
        vector<int> d = {0, 1, 0, -1, 0};
        queue<pair<int,int>> que;
        que.push({i, j});
        visited[i][j] = true;
        while(!que.empty()){
            auto [x, y] = que.front();
            que.pop();
            if (grid1[x][y] == 0) ans = false;
            for (int k = 0; k < 4; k++){
                int nx = x + d[k];
                int ny = y + d[k+1];
                if (in_range(nx, ny, m, n) && grid2[nx][ny] && !visited[nx][ny]){
                    que.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid2[i][j] && !visited[i][j]) ans += bfs(grid1, grid2, visited, i, j, m, n);
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    // vector<vector<int>> grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    // vector<vector<int>> grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
    Solution S;
    cout << S.countSubIslands(grid1, grid2) << endl;
    return 0;
}