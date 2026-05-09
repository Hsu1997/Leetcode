#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int r = min(m, n) / 2;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < r; i++){
            int x = i;
            int y = i;
            int r = m - i * 2;
            int c = n - i * 2;
            vector<int> element;
            for (int r1 = 0; r1 < r; r1++) element.push_back(grid[x+r1][y]);
            for (int c1 = 1; c1 < c; c1++) element.push_back(grid[x+r-1][y+c1]);
            for (int r1 = r-2; r1 >= 0; r1--) element.push_back(grid[x+r1][y+c-1]);
            for (int c1 = c-2; c1 > 0; c1--) element.push_back(grid[x][y+c1]);
            int s = element.size();
            int ptr = s - (k % s);
            for (int r1 = 0; r1 < r; r1++){
                ans[x+r1][y] = element[ptr];
                ptr = (ptr + 1) % s;
            }
            for (int c1 = 1; c1 < c; c1++){
                ans[x+r-1][y+c1] = element[ptr];
                ptr = (ptr + 1) % s;
            }
            for (int r1 = r-2; r1 >= 0; r1--){
                ans[x+r1][y+c-1] = element[ptr];
                ptr = (ptr + 1) % s;
            }
            for (int c1 = c-2; c1 > 0; c1--){
                ans[x][y+c1] = element[ptr];
                ptr = (ptr + 1) % s;
            }   
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{40,10},{30,20}};
    int k = 1;
    // vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // int k = 2;
    Solution S;
    vector<vector<int>> ans = S.rotateGrid(grid, k);
    for (auto& row : ans){
        for (auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}