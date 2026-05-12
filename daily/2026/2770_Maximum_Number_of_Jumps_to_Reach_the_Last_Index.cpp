#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -n);
        dp[n-1] = 0;
        for (int j = n-1; j > 0; j--){
            for (int i = j-1; i >= 0; i--){
                if (abs(nums[j] - nums[i]) <= target) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[0] > 0? dp[0] : -1;
    }
};

int main(){
    vector<int> nums = {1,3,6,4,1,2};
    int target = 2;
    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 3;
    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 0;
    Solution S;
    cout << S.maximumJumps(nums, target) << endl;
    return 0;
}