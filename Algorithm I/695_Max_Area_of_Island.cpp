#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    int row;
    int col;
    int now;
    int max_area = 0;

    #define notcount 0;
    #define counted 1;

    int maxAreaOfIsland() {
        // initialize the count grid
        row = grid.size();
        col = grid[0].size();
        // cout << "row = " << row << ", col = " << col << endl;
        
        vector<vector<int>> is_count(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1 && is_count[i][j] == 0){
                    now = 0;
                    // cout << endl;
                    // cout << "next => " << i << ", " << j << endl;
                    dfs(i, j, is_count);
                }
            }
        }
        return max_area;
    }
    void dfs(int i, int j, vector<vector<int>>& is_count){
        if (grid[i][j] == 1 && is_count[i][j] == 0){
            is_count[i][j] = 1;
            now++;
            // cout << now << " ";
            max_area = max(now, max_area);
            if (i > 0) dfs(i - 1, j , is_count);
            if (i < row - 1) dfs(i + 1, j, is_count);
            if (j > 0) dfs(i, j - 1, is_count);
            if (j < col - 1) dfs(i, j + 1, is_count);
        }
    }
};

int main(){
    Solution A;
    A.grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
              {0,0,0,0,0,0,0,1,1,1,0,0,0},
              {0,1,1,0,1,0,0,0,0,0,0,0,0},
              {0,1,0,0,1,1,0,0,1,0,1,0,0},
              {0,1,0,0,1,1,0,0,1,1,1,0,0},
              {0,0,0,0,0,0,0,0,0,0,1,0,0},
              {0,0,0,0,0,0,0,1,1,1,0,0,0},
              {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << A.maxAreaOfIsland() << endl;
    return 0;
}