#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if (b > a) swap(a,b);
        while(b > 0){
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int helper(int mask, int pair_selected, int n, vector<int>& nums, vector<int>& dp){
        if (pair_selected * 2 == n) return 0;
        if (dp[mask] != -1) return dp[mask];
        int ans = 0;
        for (int first = 0; first < n; first++){
            for (int second = first+1; second < n; second++){
                if ((mask >> first) & 1 || (mask >> second) & 1) continue;
                int new_mask = mask | (1 << first) | (1 << second);
                int current_score = (1 + pair_selected) * gcd(nums[first], nums[second]);
                int remain_score = helper(new_mask, pair_selected+1, n, nums, dp);
                ans = max(ans, current_score + remain_score);
            }
        }
        dp[mask] = ans;
        return ans;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int final = (1 << n) - 1;
        vector<int> dp(1 << n, -1);
        return helper(0, 0, n, nums, dp);
    }
};

int main(){
    // vector<int> nums = {1,2};
    // vector<int> nums = {3,4,6,8};
    // vector<int> nums = {1,2,3,4,5,6};
    vector<int> nums = {109497,983516,698308,409009,310455,528595,524079,18036,341150,641864,913962,421869,943382,295019};
    Solution S;
    cout << S.maxScore(nums) << endl;
    return 0;
}