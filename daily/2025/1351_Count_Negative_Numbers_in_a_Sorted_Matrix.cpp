#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] < 0){
                    ans += (n - j);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    // vector<vector<int>> grid = {{3,2},{1,0}};
    Solution S;
    cout << S.countNegatives(grid) << endl;
    return 0;
}