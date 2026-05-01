#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return true;
        vector<vector<int>> inAndOut(7, vector<int>(4, -1));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dirReverse = {1,0,3,2};
        // 0: up
        // 1: down
        // 2: left
        // 3: right
        inAndOut[1][2] = 3;
        inAndOut[1][3] = 2;
        inAndOut[2][0] = 1;
        inAndOut[2][1] = 0;
        inAndOut[3][2] = 1;
        inAndOut[3][1] = 2;
        inAndOut[4][1] = 3;
        inAndOut[4][3] = 1;
        inAndOut[5][0] = 2;
        inAndOut[5][2] = 0;
        inAndOut[6][0] = 3;
        inAndOut[6][3] = 0;
        queue<pair<pair<int,int>, int>> que;
        int currStreet = grid[0][0];
        for (int in = 0; in < 4; in++){
            if (inAndOut[currStreet][in] != -1){
                int d = inAndOut[currStreet][in];
                int dx = dir[d][0];
                int dy = dir[d][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n){
                    que.push({{dx,dy}, dirReverse[d]});
                }
            }
        }
        visited[0][0] = true;
        while(!que.empty()){
            auto [pos, in] = que.front();
            auto [x, y] = pos;
            que.pop();
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
            currStreet = grid[x][y];
            if (inAndOut[currStreet][in] == -1) continue;
            if (x == m - 1 && y == n - 1) return true;
            visited[x][y] = true;
            int d = inAndOut[currStreet][in];
            int dx = dir[d][0];
            int dy = dir[d][1];
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                que.push({{nx, ny}, dirReverse[d]});
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};
    // vector<vector<int>> grid = {{1,2,1},{1,2,1}};
    // vector<vector<int>> grid = {{1,1,2}};
    // vector<vector<int>> grid = {{4,1},{6,1}};
    Solution S;
    cout << S.hasValidPath(grid) << endl;
    return 0;
}