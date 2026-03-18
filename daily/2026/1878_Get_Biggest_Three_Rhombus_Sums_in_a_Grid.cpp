#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int m, n;
    void put(vector<int>& ans, int i){
        if (i > ans[0]){
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = i;
        }
        else if (i > ans[1] && i != ans[0]){
            ans[2] = ans[1];
            ans[1] = i;
        }
        else if (i > ans[2] && i != ans[0] && i != ans[1]){
            ans[2] = i;
        }
        else return;
        return;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> ans(3, 0);
        // acc1 : '\'
        // acc2 : '/'
        vector<vector<int>> acc1(m + 1, vector<int>(n + 2, 0));
        vector<vector<int>> acc2(m + 1, vector<int>(n + 2, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                acc1[i+1][j+1] = grid[i][j] + acc1[i][j];
                acc2[i+1][j+1] = grid[i][j] + acc2[i][j+2];
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                put(ans, grid[i][j]);
                for (int l = 1; l < min(m, n); l++){
                    int left = j - l;
                    int right = j + l;
                    int top = i - l;
                    int down = i + l;
                    if (left < 0 || right >= n || top < 0 || down >= m) break;
                    // (i, left) (top, j) (i, right) (down, j)
                    int curr = (acc2[i+1][left+1] - acc2[top][j+2]) + 
                               (acc1[i+1][right+1] - acc1[top][j]) + 
                               (acc2[down+1][j+1] - acc2[i][right+2]) + 
                               (acc1[down+1][j+1] - acc1[i][left]) -
                               (grid[i][left] + grid[top][j] + grid[i][right] + grid[down][j]);
                    put(ans, curr);
                }
            }
        }
        while(!ans.empty() && ans.back() == 0) ans.pop_back();
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    // vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> grid = {{7,7,7}};
    Solution S;
    vector<int> ans = S.getBiggestThree(grid);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}