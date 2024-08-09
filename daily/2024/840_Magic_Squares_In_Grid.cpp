#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsMagic(vector<vector<int>>& grid, int x, int y){
        vector<bool> contain(10, false);
        for (int i = x; i < x + 3; i++){
            for (int j = y; j < y + 3; j++){
                contain[grid[i][j]] = true;
            }
        }
        for (int i = 1; i < 10; i++) if (!contain[i]) return false;
        for (int i = x; i < x + 3; i++){
            if (grid[i][y] + grid[i][y + 1] + grid[i][y + 2] != 15) return false;
        }
        for (int j = y; j < y + 3; j++){
            if (grid[x][j] + grid[x + 1][j] + grid[x + 2][j] != 15) return false;
        }
        if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != 15) return false;
        if (grid[x+2][y] + grid[x + 1][y + 1] + grid[x][y + 2] != 15) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;
        int ans = 0;
        for (int i = 0; i < m - 2; i++){
            for (int j = 0; j < n - 2; j++){
                if (IsMagic(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    // vector<vector<int>> grid = {{8}};
    Solution S;
    cout << S.numMagicSquaresInside(grid) << endl;
    return 0;
}