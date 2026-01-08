#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> acc(m, vector<int>(n, 0));
        dp[0][0] = nums1[0] * nums2[0];
        acc[0][0] = dp[0][0];
        for (int i = 1; i < m; i++){
            dp[i][0] = nums1[i] * nums2[0];
            acc[i][0] = max(acc[i-1][0], dp[i][0]);
        }
        for (int j = 1; j < n; j++){
            dp[0][j] = nums1[0] * nums2[j];
            acc[0][j] = max(acc[0][j-1], dp[0][j]);
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = nums1[i] * nums2[j] + max(0, acc[i-1][j-1]);
                acc[i][j] = max({acc[i-1][j], acc[i][j-1], dp[i][j]});
            }
        }
        return acc[m-1][n-1];
    }
};

int main(){
    vector<int> nums1 = {2,1,-2,5};
    vector<int> nums2 = {3,0,-6};
    // vector<int> nums1 = {3,-2};
    // vector<int> nums2 = {2,-6,7};
    // vector<int> nums1 = {-1,-1};
    // vector<int> nums2 = {1,1};
    Solution S;
    cout << S.maxDotProduct(nums1, nums2) << endl;
    return 0;
}