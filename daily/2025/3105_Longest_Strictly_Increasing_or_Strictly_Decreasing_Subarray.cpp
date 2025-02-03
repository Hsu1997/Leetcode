#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int curr = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i-1]) curr++;
            else curr = 1;
            ans = max(ans, curr);
        }
        curr = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] < nums[i-1]) curr++;
            else curr = 1;
            ans = max(ans, curr);
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