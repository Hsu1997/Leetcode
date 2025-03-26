#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int remainder = grid[0][0] % x;
        vector<int> nums;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] % x != remainder) return -1;
                nums.push_back(grid[i][j] / x);
            }
        }
        nth_element(nums.begin(), nums.begin() + n * m / 2, nums.end());
        int median = nums[n * m / 2];
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans += abs(grid[i][j] / x - median);
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;
    // vector<vector<int>> grid = {{1,5},{2,3}};
    // int x = 1;
    // vector<vector<int>> grid = {{1,2},{3,4}};
    // int x = 2;
    // vector<vector<int>> grid = {{931,128},{639,712}};
    // int x = 73;
    Solution S;
    cout << S.minOperations(grid, x) << endl;
    return 0;
}