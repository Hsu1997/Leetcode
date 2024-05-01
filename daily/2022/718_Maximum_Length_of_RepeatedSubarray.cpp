#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<int> dp(nums2.size()+1, 0);
        vector<int> dp_temp(nums2.size()+1, 0);
        
        for (int i = 1; i <= nums1.size(); i++){
            for (int j = 1; j <= nums2.size(); j++){
                if (nums1[i-1] == nums2[j-1]) dp_temp[j] = dp[j-1]+1;
                else dp_temp[j] = 0;
                ans = max(ans, dp_temp[j]);
            }
            swap(dp, dp_temp);
            // for (auto i : dp) cout << i << " ";
            // cout << endl;
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    // vector<int> nums1 = {0,0,0,0,0};
    // vector<int> nums2 = {0,0,0,0,0};

    Solution S;
    cout << S.findLength(nums1, nums2) << endl;
    return 0;
}