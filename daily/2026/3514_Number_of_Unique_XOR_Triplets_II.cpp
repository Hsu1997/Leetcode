#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<vector<int>> dp(2048, vector<int>(4, 0));
        for (int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            for (int i = 0; i < 2048; i++){
                if (dp[i][2]) dp[i ^ curr][3] |= 1;
                if (dp[i][1]) dp[i][3] |= 1;
            }
            dp[curr][3] |= 1;
            for (int i = 0; i < 2048; i++){
                if (dp[i][1]) dp[i ^ curr][2] |= 1;
            }
            dp[0][2] |= 1;
            dp[curr][1] |= 1;
        }
        int ans = 0;
        for (int i = 0; i < 2048; i++) if (dp[i][3]) ans++;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3};
    // vector<int> nums = {6,7,8,9};
    Solution S;
    cout << S.uniqueXorTriplets(nums) << endl;
    return 0;
}