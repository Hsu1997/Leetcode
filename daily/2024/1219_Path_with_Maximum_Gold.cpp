#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<int> x_d = {-1,0,1,0};
    vector<int> y_d = {0,1,0,-1};
    int max_gold = 0;

    void dfs(int x, int y, int acc, vector<vector<int>>& grid){
        // cout << "dfs " << x << ", " << y << endl;
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return;
        acc += grid[x][y];
        int temp = grid[x][y];
        grid[x][y] = 0;
        if (acc > max_gold) max_gold = acc;
        for (int d = 0; d < 4; d++){
            dfs(x+x_d[d], y+y_d[d], acc, grid);
        }
        grid[x][y] = temp;
        return;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int max = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                // cout << "test" << endl;
                dfs(i, j, 0, grid);
            }
        }
        // cout << "start at " << start_position.first << ", " << start_position.second << ", max gold = " << max_gold << endl;
        return max_gold;
    }
};

int main(){
    // vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    Solution S;
    cout << S.getMaximumGold(grid) << endl;
    return 0;
}