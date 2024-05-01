#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++){
            // for (auto j : ans) cout << j << " ";
            // cout << endl;
            if (nums[i] > ans.back()) ans.push_back(nums[i]);
            else *lower_bound(ans.begin(), ans.end(), nums[i]) = nums[i];
        }

        // for (auto j : ans) cout << j << " ";
        // cout << endl;

        return ans.size();
    }
};

int main(){
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,1,3,2,3};
    vector<int> nums = {0,0,0,1,1,1};
    Solution S;
    cout << S.lengthOfLIS(nums) << endl;
    return 0;
}