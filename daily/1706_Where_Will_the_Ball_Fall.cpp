#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);
        for (int k = 0; k < n; k++){
            int i = 0;
            int j = k;
            while(i < m && j < n){
                if (grid[i][j] == 1){
                    if (j == n-1 || grid[i][j+1] == -1) break;
                    j++;
                }
                else if (grid[i][j] == -1){
                    if (j == 0 || grid[i][j-1] == 1) break;
                    j--;
                }
                i++;
            }
            if (i == m) ans[k] = j;
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    // vector<vector<int>> grid = {{-1}};
    vector<vector<int>> grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    Solution S;
    vector<int> ans = S.findBall(grid);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}