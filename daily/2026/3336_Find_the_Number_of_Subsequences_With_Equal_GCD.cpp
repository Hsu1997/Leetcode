#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> dp(201, vector<int>(201, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            vector<vector<int>> next(201, vector<int>(201, 0));
            for (int l = 0; l <= 200; l++){
                for (int r = 0; r <= 200; r++){
                    if (dp[l][r] == 0) continue;
                    next[gcd(curr, l)][r] = (next[gcd(curr, l)][r] + dp[l][r]) % mod;
                    next[l][gcd(curr, r)] = (next[l][gcd(curr, r)] + dp[l][r]) % mod;
                    next[l][r] = (next[l][r] + dp[l][r]) % mod;
                }
            }
            dp.swap(next);
        }
        int ans = 0;
        for (int i = 1; i <= 200; i++) ans = (ans + dp[i][i]) % mod;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {10,20,30};
    // vector<int> nums = {1,1,1,1};
    // vector<int> nums = {26,30,23,23,21};
    Solution S;
    cout << S.subsequencePairCount(nums) << endl;
    return 0;
}