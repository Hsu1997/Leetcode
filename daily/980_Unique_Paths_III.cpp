#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    int non_obstacle = 0;
    int x;
    int y;
    vector<int> xd = {-1,0,1,0};
    vector<int> yd = {0,1,0,-1};

    bool in_board(int i, int j) {return (i >= 0 && i < x && j >= 0 && j < y);}

    void dfs(vector<vector<int>> &grid, int i, int j, int visited){
        if (grid[i][j] == -1) return;
        else if (grid[i][j] == 2){
            // cout << "now looking at the end, visited = " << visited << endl;
            if (visited-1 == non_obstacle){
                ans++;
                // cout << "find!!" << endl;
            }
            return;
        }
        else{
            // cout << "now looking at " << i << ", " << j << ", visited = " << visited << endl;
            grid[i][j] = -1;
            for (int d = 0; d < 4; d++){
                if (in_board(i+xd[d], j+yd[d])){
                    dfs(grid, i+xd[d], j+yd[d], visited+1);
                }
            }
            grid[i][j] = 0;
        }
    }
    int uniquePathsIII(vector<vector<int>> &grid){
        x = grid.size();
        y = grid[0].size();
        int start_x = -1;
        int start_y = -1;
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if (grid[i][j] == 0) non_obstacle++;
                if (grid[i][j] == 1) start_x = i, start_y = j;
            }
        }
        // cout << "start : " << start_x << ", " << start_y << endl;
        grid[start_x][start_y] = 0;
        dfs(grid, start_x, start_y, 0);
        return ans;
    }
};

int main(){
    // vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    vector<vector<int>> grid = {{0,1},{2,0}};
    Solution S;
    cout << S.uniquePathsIII(grid) << endl;
    return 0;
}