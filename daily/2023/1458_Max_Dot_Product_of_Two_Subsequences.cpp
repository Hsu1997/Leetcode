#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // if (nums1.size() < nums2.size()) swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = nums1[0] * nums2[0];
        for (int j = 1; j < n; j++) dp[0][j] = max(dp[0][j-1], nums1[0] * nums2[j]);
        // for (auto c : dp[0]) cout << c << " ";
        // cout << endl;
        for (int i = 1; i < m; i++){
            dp[i % 2][0] = max(nums1[i] * nums2[0], dp[(i - 1) % 2][0]);
            for (int j = 1; j < n; j++){
                dp[i % 2][j] = max({nums1[i] * nums2[j] + max(0, dp[(i - 1) % 2][j - 1]), dp[(i - 1) % 2][j], dp[i % 2][j - 1]});
            }
            // for (auto c : dp[i % 2]) cout << c << " ";
            // cout << endl;
        }
        return dp[(m - 1) % 2].back();
    }
};

int main(){
    // vector<int> nums1 = {2,1,-2,5};
    // vector<int> nums2 = {3,0,-6};
    // vector<int> nums1 = {3,-2};
    // vector<int> nums2 = {2,-6,7};
    // vector<int> nums1 = {-1,-1};
    // vector<int> nums2 = {1,1};
    // vector<int> nums1 = {-5,3,-5,-3,1};
    // vector<int> nums2 = {-2,4,2,5,-5};
    vector<int> nums1 = {-3,-8,3,-10,1,3,9};
    vector<int> nums2 = {9,2,3,7,-9,1,-8,5,-1,-1};
    Solution S;
    cout << S.maxDotProduct(nums1, nums2) << endl;
    return 0;
}