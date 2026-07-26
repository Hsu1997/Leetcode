#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        long long dp[2][3];
        // [max, min][numbers of multiplier]
        dp[0][0] = max(nums[0], nums[1]);
        dp[0][1] = nums[0] * nums[1];
        dp[0][2] = INT_MIN;
        dp[1][0] = min(nums[0], nums[1]);
        dp[1][1] = nums[0] * nums[1];
        dp[1][2] = INT_MAX;
        for (int i = 2; i < n; i++){
            int num = nums[i];
            dp[0][2] = max({dp[0][2], dp[0][1] * num, dp[1][1] * num});
            dp[1][2] = min({dp[1][2], dp[0][1] * num, dp[1][1] * num});
            dp[0][1] = max({dp[0][1], dp[0][0] * num, dp[1][0] * num});
            dp[1][1] = min({dp[1][1], dp[0][0] * num, dp[1][0] * num});
            dp[0][0] = max(dp[0][0], 1LL * num);
            dp[1][0] = min(dp[1][0], 1LL * num);
        }
        return dp[0][2];
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {1,2,3,4};
    // vector<int> nums = {-1,-2,-3};
    Solution S;
    cout << S.maximumProduct(nums) << endl;
    return 0;
}