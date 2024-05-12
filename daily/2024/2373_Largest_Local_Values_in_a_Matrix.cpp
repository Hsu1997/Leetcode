#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for (int i = 1; i < n-1; i++){
            for (int j = 1; j < n-1; j++){
                int temp = 0;
                for (int k = i-1; k < i+2; k++){
                    for (int l = j-1; l < j+2; l++){
                        temp = max(temp, grid[k][l]);
                    }
                }
                ans[i-1][j-1] = temp;
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> grid = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>> grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    Solution S;
    vector<vector<int>> ans = S.largestLocal(grid);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}