#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        if (n == 2) return nums[0] == nums[1];
        vector<bool> dp(n, false);
        dp[1] = (nums[0] == nums[1]);
        dp[2] = (dp[1] && nums[1] == nums[2]);
        if (nums[2]-nums[1] == 1 && nums[1]-nums[0] == 1) dp[2] = true;
        for (int i = 3; i < n; i++){
            if (nums[i] == nums[i-1]) dp[i] = dp[i] || dp[i-2];
            if (nums[i] == nums[i-1] && nums[i] == nums[i-2]) dp[i] = dp[i] || dp[i-3];
            if (nums[i]-nums[i-1] == 1 && nums[i-1]-nums[i-2] == 1) dp[i] = dp[i] || dp[i-3];
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return dp[n-1];
    }
};

int main(){
    vector<int> nums = {4,4,4,5,6};
    // vector<int> nums = {1,1,1,2};
    Solution S;
    cout << S.validPartition(nums) << endl;
    return 0;
}