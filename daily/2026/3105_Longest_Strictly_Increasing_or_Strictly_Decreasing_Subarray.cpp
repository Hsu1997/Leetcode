#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incres = 1;
        int decres = 1;
        int ans = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] <= nums[i-1]) incres = 0;
            if (nums[i] >= nums[i-1]) decres = 0;
            incres++;
            decres++;
            ans = max({ans, incres, decres});
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,4,3,3,2};
    // vector<int> nums = {3,3,3,3};
    // vector<int> nums = {3,2,1};
    Solution S;
    cout << S.longestMonotonicSubarray(nums) << endl;
    return 0;
}