#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& nums, vector<vector<int>>& dp, int index, int mask){
        if (index == nums.size()) return 0;
        if (dp[index][mask] != -1) return dp[index][mask];
        int row = nums[index][1];
        if (mask & (1 << row)) return dp[index][mask] = helper(nums, dp, index + 1, mask);
        int find_next_diff_num = index + 1;
        while(find_next_diff_num < nums.size() && nums[index][0] == nums[find_next_diff_num][0]) find_next_diff_num++;
        int take = nums[index][0] + helper(nums, dp, find_next_diff_num, mask | (1 << row));
        int not_take = helper(nums, dp, index + 1, mask);
        return dp[index][mask] = max(take, not_take);
    }

    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m * n, vector<int>(1 << 10, -1));
        vector<vector<int>> nums;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) nums.push_back({grid[i][j], i, j});
        }
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b){return a[0] > b[0];});
        helper(nums, dp, 0, 0);
        return dp[0][0];
    }
};

int main(){
    // vector<vector<int>> grid = {{1,2,3},{4,3,2},{1,1,1}};
    vector<vector<int>> grid = {{8,7,6},{8,3,2}};
    Solution S;
    cout << S.maxScore(grid) << endl;
    return 0;
}