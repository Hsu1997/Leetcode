#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> acc(n, -1);
        int curr = 0;
        for (int i = 0; i < k; i++) curr += nums[i];
        acc[k-1] = curr;
        for (int i = k; i < n; i++){
            curr = curr - nums[i-k] + nums[i];
            acc[i] = curr;
        }
        // for (int i : acc) cout << i << " ";
        // cout << endl << endl;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        curr = acc[k-1];
        int idx = k-1;
        for (int i = k-1; i < n; i++){
            if (acc[i] > curr){
                curr = acc[i];
                idx = i;
            }
            dp[i][0] = curr;
            dp[i][1] = idx;
        }
        // for (auto i : dp) cout << i[0] << " ";
        // cout << endl;
        // for (auto i : dp) cout << i[1] << " ";
        // cout << endl;
        for (int r = 2; r <= 3; r++){
            vector<int> temp_dp(n, -1);
            int curr = 0;
            int idx = 0;
            for (int i = r * k - 1; i < n; i++){
                int temp = acc[i] + dp[i-k][0];
                if (temp > curr){
                    curr = temp;
                    idx = i;
                }
                temp_dp[i] = curr;
                dp[i][r] = idx;
            }
            for (int i = 0; i < n; i++) dp[i][0] = temp_dp[i];
            // cout << endl;
            // for (auto i : dp) cout << i[0] << " ";
            // cout << endl;
            // for (auto i : dp) cout << i[r] << " ";
            // cout << endl;
        }
        int third = dp[n-1][3];
        int second = dp[third-k][2];
        int first = dp[second-k][1];
        return {first-k+1, second-k+1, third-k+1};
    }
};

int main(){
    vector<int> nums = {1,2,1,2,6,7,5,1};
    int k = 2;
    // vector<int> nums = {1,2,1,2,1,2,1,2,1};
    // int k = 2;
    Solution S;
    vector<int> ans = S.maxSumOfThreeSubarrays(nums, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}