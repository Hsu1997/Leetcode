#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();
        long long curr = 1;
        vector<vector<int>> suffix(m, vector<int>(n));
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                suffix[i][j] = curr;
                curr = (curr * grid[i][j]) % mod;
            }
        }
        curr = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans[i][j] = (curr * suffix[i][j]) % mod;
                curr = (curr * grid[i][j]) % mod;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2},{3,4}};
    // vector<vector<int>> grid = {{12345},{2},{1}};
    Solution S;
    vector<vector<int>> ans = S.constructProductMatrix(grid);
    for (auto row : ans){
        for (int col : row) cout << col << " ";
        cout << endl;
    }
    return 0;
}