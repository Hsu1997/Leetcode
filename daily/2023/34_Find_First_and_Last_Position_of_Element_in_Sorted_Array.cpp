#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) return {-1,-1};
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        vector<int> ans = {(int)(it1 - nums.begin()), (int)(it2 - nums.begin() - 1)};
        return ans;
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    // vector<int> nums = {5,7,7,8,8,10};
    // int target = 6;
    // vector<int> nums = {};
    // int target = 0;
    Solution S;
    vector<int> ans = S.searchRange(nums, target);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}