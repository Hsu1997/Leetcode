#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int ans = 0;

    int subproblem(vector<vector<int> >& grid, int i, int j){
        if (grid[i][j] < 1) return 0;
        grid[i][j] = -1;
        int left = (j-1 >= 0)? subproblem(grid, i, j-1): 0;
        int right = (j+1 < n)? subproblem(grid, i, j+1): 0;
        int up = (i-1 >= 0)? subproblem(grid, i-1, j): 0;
        int down = (i+1 < m)? subproblem(grid, i+1, j): 0;
        // cout << "(" << i << "," << j << ") : " << left << ", " << right << ", " << up << ", " << down << endl;
        return 1 + left + right + up + down;
    }

    int maxAreaOfIsland(vector<vector<int> >& grid){
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0) grid[i][j] = -1;
                else if (grid[i][j] == -1) continue;
                else{
                    grid[i][j] = subproblem(grid, i, j);
                    // cout << grid[i][j] << endl;
                    ans = max(ans, grid[i][j]);
                }
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
    //                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
    //                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
    //                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
    //                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
    //                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
    Solution S;
    cout << S.maxAreaOfIsland(grid) << endl;
    return 0;
}