#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int zero = (nums[0] == 0)? 1 : 0;
        int res = nums[0];
        for (int i = 1; i < n; i++){
            if (nums[i] == 0) zero++;
            res ^= nums[i];
        }
        if (zero == n) return 0;
        return (res == 0)? (n - 1) : n;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {2,3,4};
    // vector<int> nums = {0};
    // vector<int> nums = {1};
    // vector<int> nums = {0,0,0,0,0};
    Solution S;
    cout << S.longestSubsequence(nums) << endl;
    return 0;
}