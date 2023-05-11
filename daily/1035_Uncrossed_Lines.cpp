#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 || j == 0){
                    if (i == j) dp[i][j] = (nums1[i] == nums2[j]);
                    else if (nums1[i] == nums2[j]) dp[i][j] = 1;
                    else if (i == 0) dp[i][j] = dp[i][j-1];
                    else if (j == 0) dp[i][j] = dp[i-1][j];
                }
                else{
                    if (nums1[i] == nums2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        for (auto i : dp){
            for (auto j : i) cout << j << " ";
            cout << endl;
        }
        return dp[m-1][n-1];
    }
};

int main(){
    // vector<int> nums1 = {1,4,2};
    // vector<int> nums2 = {1,2,4};
    // vector<int> nums1 = {2,5,1,2,5};
    // vector<int> nums2 = {10,5,2,1,5,2};
    vector<int> nums1 = {1,3,7,1,7,5};
    vector<int> nums2 = {1,9,2,5,1};
    Solution S;
    cout << S.maxUncrossedLines(nums1, nums2) << endl;
    return 0;
}