#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end());
        vector<int> cnt(51, 0);
        for (int i : nums) cnt[i]++;
        if (k == 1){
            for (int i = 50; i >= 0; i--){
                if (cnt[i] == 1) return i;
            }
        }
        int res = -1;
        if (cnt[nums[0]] == 1) res = max(res, nums[0]);
        if (cnt[nums[n-1]] == 1) res = max(res, nums[n-1]);
        return res;
    }
};

int main(){
    vector<int> nums = {3,9,2,1,7};
    int k = 3;
    // vector<int> nums = {3,9,7,2,1,7};
    // int k = 4;
    // vector<int> nums = {0,0};
    // int k = 1;
    // vector<int> nums = {0,0};
    // int k = 2;
    // vector<int> nums = {3,1,7,10,0};
    // int k = 1;
    Solution S;
    cout << S.largestInteger(nums, k) << endl;
    return 0;
}