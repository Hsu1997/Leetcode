#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++){
            for (auto j : nums) if (j <= i) dp[i] += dp[i - j];
        }

        // for (auto i : sum) cout << i << " ";
        // cout << endl;

        return dp[target];
    }
};

int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    // vector<int> nums = {9};
    // int target = 3;
    Solution S;
    cout << S.combinationSum4(nums, target) << endl;
    return 0;
}