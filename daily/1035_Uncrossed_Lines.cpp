#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(2, vector<int>(n+1,0));
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (nums1[i-1] == nums2[j-1]) dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
                else dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[m%2][n];
    }
};

int main(){
    // vector<int> nums1 = {1,4,2};
    // vector<int> nums2 = {1,2,4};
    vector<int> nums1 = {2,5,1,2,5};
    vector<int> nums2 = {10,5,2,1,5,2};
    // vector<int> nums1 = {1,3,7,1,7,5};
    // vector<int> nums2 = {1,9,2,5,1};
    // vector<int> nums1 = {2};
    // vector<int> nums2 = {3,1,1,3,3};
    Solution S;
    cout << S.maxUncrossedLines(nums1, nums2) << endl;
    return 0;
}