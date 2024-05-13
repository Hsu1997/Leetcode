#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            if (grid[i][0] == 0){
                for (int j = 0; j < n; j++) grid[i][j] ^= 1;
            }
            else continue;
        }
        // for (auto i : grid){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        int ans = 0;
        for (int j = 0; j < n; j++){
            int temp = 0;
            for (int i = 0; i < m; i++) if (grid[i][j] == 1) temp++;
            temp = max(temp, m - temp);
            ans = ans * 2 + temp;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    // vector<vector<int>> grid = {{0}};
    Solution S;
    cout << S.matrixScore(grid) << endl;
    return 0;
}