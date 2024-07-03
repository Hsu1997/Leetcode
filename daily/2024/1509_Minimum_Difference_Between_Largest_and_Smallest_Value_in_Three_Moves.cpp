#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        int ans = INT_MAX;
        for (int k = 0; k < 4; k++){
            ans = min(ans, abs(nums[k] - nums[nums.size() - 4 + k]));
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,3,2,4};
    // vector<int> nums = {1,5,0,10,14};
    // vector<int> nums = {3,100,20};
    // vector<int> nums = {6,6,0,1,1,4,6};
    Solution S;
    cout << S.minDifference(nums) << endl;
    return 0;
}