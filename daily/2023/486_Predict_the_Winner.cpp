#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        for (int i = 0; i < n; i++) dp[i] = nums[i];
        for (int diff = 1; diff < n; diff++){
            // for (auto i : dp) cout << i << " ";
            // cout << endl;
            // vector<int> temp(n,0);
            for (int left = 0; left < n - diff; left++){
                int right = left + diff;
                dp[left] = max(nums[left] - dp[left+1], nums[right] - dp[left]);
            }
            // swap(temp, dp);
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return dp[0] >= 0;
    }
};

int main(){
    // vector<int> nums = {1,5,2};
    vector<int> nums = {1,5,233,7};
    Solution S;
    cout << S.PredictTheWinner(nums) << endl;
    return 0;
}