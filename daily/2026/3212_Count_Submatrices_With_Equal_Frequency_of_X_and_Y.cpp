#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<bool> valid(n, false);
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++){
            int acc = 0;
            bool v = false;
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 'X') valid[j] = true;
                if (grid[i][j] != '.') prev[j] += (grid[i][j] == 'X')? 1 : -1;
                v |= valid[j];
                acc += prev[j];
                if (v && (acc == 0)) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};
    // vector<vector<char>> grid = {{'X','X'},{'X','Y'}};
    // vector<vector<char>> grid = {{'.','.'},{'.','.'}};
    Solution S;
    cout << S.numberOfSubmatrices(grid) << endl;
    return 0;
}