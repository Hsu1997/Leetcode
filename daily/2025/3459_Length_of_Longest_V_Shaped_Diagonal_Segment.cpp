#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 0 : ↗  1 : ↘  2 : ↙  3 : ↖
        vector<pair<int,int>> dir = {{-1,1},{1,1},{1,-1},{-1,-1}};
        vector<vector<vector<int>>> straight(m, vector<vector<int>>(n, vector<int>(4, -1)));
        vector<vector<vector<int>>> turn(m, vector<vector<int>>(n, vector<int>(4, -1)));

        function<bool(int,int)> valid = [&](int i, int j) -> bool { return i >= 0 && j >= 0 && i < m && j < n; };
        function<int(int)> alt = [&](int v) -> int { return (v == 0)? 2 : 0; };
        function<int(int,int,int)> go_straight = [&](int i, int j, int d)->int{
            if (!valid(i, j) || grid[i][j] == 1) return 0;
            if (straight[i][j][d] != -1) return straight[i][j][d];
            int v = grid[i][j];
            int x = i + dir[d].first;
            int y = j + dir[d].second;
            if (valid(x, y) && grid[x][y] == alt(v)) return straight[i][j][d] = 1 + go_straight(x, y, d);
            else return straight[i][j][d] = 1;
        };
        function<int(int,int,int)> can_turn = [&](int i, int j, int d)->int{
            if (!valid(i, j) || grid[i][j] == 1) return 0;
            if (turn[i][j][d] != -1) return turn[i][j][d];
            int v = grid[i][j];
            int nx = i + dir[d].first;
            int ny = j + dir[d].second;
            int s = 1;
            int t = 1;
            if (valid(nx, ny) && grid[nx][ny] == alt(v)) s += can_turn(nx, ny, d);
            int td = (d + 1) % 4;
            int tx = i + dir[td].first;
            int ty = j + dir[td].second;
            if (valid(tx, ty) && grid[tx][ty] == alt(v)) t += go_straight(tx, ty, td);
            return turn[i][j][d] = max(s, t);
        };

        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != 1) continue;
                ans = max(ans, 1);
                for (int d = 0; d < 4; d++){
                    int nx = i + dir[d].first;
                    int ny = j + dir[d].second;
                    if (valid(nx, ny) && grid[nx][ny] == 2){
                        ans = max(ans, 1 + can_turn(nx, ny, d));
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    // vector<vector<int>> grid = {{2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    // vector<vector<int>> grid = {{1,2,2,2,2},{2,2,2,2,0},{2,0,0,0,0},{0,0,2,2,2},{2,0,0,2,0}};
    // vector<vector<int>> grid = {{1}};
    // vector<vector<int>> grid = {{1,2,2},{1,0,2}};
    // vector<vector<int>> grid = {{1,1,1,2,0,0},{0,0,0,0,1,2}};
    Solution S;
    cout << S.lenOfVDiagonal(grid) << endl;
    return 0;
}