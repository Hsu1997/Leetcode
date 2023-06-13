#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;

    bool compare_row_and_column(int r, int c, vector<vector<int>>& grid){
        for (int k = 0; k < n; k++) if (grid[r][k] != grid[k][c]) return false;
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (compare_row_and_column(i,j, grid)) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    // vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution S;
    cout << S.equalPairs(grid) << endl;
    return 0;
}