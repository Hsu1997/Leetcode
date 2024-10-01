#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // using bool in C++ will slower than int because system need to transfer bit to Bytes size before store it.
    vector<vector<vector<int>>> create_dp_table(vector<int>& nums, int k){
        // dp[end_pos][len][1-127] :
        // (1) Take : dp[end_pos-1][len-1][1-127 | nums[i]]
        // (2) Not Take : dp[end_pos-1][len][1-127]
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(128, 0)));
        dp[0][0][0] = 1;
        dp[0][1][nums[0]] = 1;
        for (int i = 1; i < n; i++){
            dp[i][0][0] = 1;
            for (int len = 1; len <= k; len++){
                for (int val = 0; val < 128; val++){
                    int x = nums[i];
                    dp[i][len][val] |= dp[i-1][len][val];
                    dp[i][len][val | x] |= dp[i-1][len-1][val];
                }
            }
        }
        return dp;
    }
    int maxValue(vector<int>& nums, int k) {
        vector<vector<vector<int>>> left = create_dp_table(nums, k);
        reverse(nums.begin(), nums.end());
        vector<vector<vector<int>>> right = create_dp_table(nums, k);
        reverse(right.begin(), right.end());
        int n = nums.size();
        int ans = 0;
        for (int mid = k-1; mid + k < n; mid++){
            for (int l = 1; l < 128; l++){
                for (int r = 1; r < 128; r++){
                    if (left[mid][k][l] && right[mid+1][k][r]) ans = max(ans, l ^ r);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,6,7};
    int k = 1;
    // vector<int> nums = {4,2,5,6,7};
    // int k = 2;
    Solution S;
    cout << S.maxValue(nums, k) << endl;
    return 0;
}