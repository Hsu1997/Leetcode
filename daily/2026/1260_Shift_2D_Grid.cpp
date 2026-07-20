#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m * n; i++){
            int t = (i + k) % (m * n);
            ans[t / n][t % n] = grid[i / n][i % n];
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    // vector<vector<int>> grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    // int k = 4;
    // vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    // int k = 9;
    // vector<vector<int>> grid = {{1},{2},{3},{4},{7},{6},{5}};
    // int k = 2;
    Solution S;
    vector<vector<int>> ans = S.shiftGrid(grid, k);
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}