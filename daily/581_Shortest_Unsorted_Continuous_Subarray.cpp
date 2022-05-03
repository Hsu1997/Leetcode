#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        if (nums.size() == 2) return (nums[0] <= nums[1])? 0:2;

        int r = nums.size() - 2;
        while(nums[r] <= nums[r + 1] && r > 0) r--;
        int MAX = -100001;
        for (int i = 0; i <= r; i++) MAX = max(MAX, nums[i]);
        while(r < nums.size() - 1 && nums[r + 1] < MAX) r++;
        // cout << r << endl;

        int l = 1;
        while(nums[l] >= nums[l-1] && l < nums.size() - 1) l++; 
        int MIN = 100001;
        for (int i = l; i <= r; i++) MIN = min(MIN, nums[i]);
        while(l > 0 && nums[l - 1] > MIN) l--;
        // cout << l << endl;

        return (r >= l)? r - l + 1 : 0;
    }
};

int main(){
    vector<int> nums = {1,2,3,3,3};
    // vector<int> nums = {2,6,4,8,10,9,15};
    // vector<int> nums = {2,1};
    // vector<int> nums = {1,2,3,4};
    Solution S;
    cout << S.findUnsortedSubarray(nums) << endl;
    return 0;
}