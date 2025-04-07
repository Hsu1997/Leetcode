#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int max_element = 0;
        for (int num : nums){
            max_element = max(max_element, num);
            total += num;
        }
        if (total % 2 == 1 || max_element > total / 2) return false;
        total /= 2;
        vector<vector<bool>> dp(2, vector<bool>(total+1, false));
        dp[0][0] = true;
        dp[1][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++){
            int curr = nums[i];
            for (int j = 1; j <= total; j++){
                dp[i%2][j] = dp[(i+1)%2][j];
                if (j - curr >= 0) dp[i%2][j] = dp[i%2][j] || dp[(i+1)%2][j-curr];
            }
            if (dp[i%2][total]) return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,5,11,5};
    // vector<int> nums = {1,2,3,5};
    // vector<int> nums = {100,4,6};
    // vector<int> nums = {1,5,10,6};
    Solution S;
    cout << S.canPartition(nums) << endl;
    return 0;
}

