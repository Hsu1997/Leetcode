#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int start = n - 1;
        int end = n - 1;
        for (int i = 0; i < n; i++){
            if (nums[i] + nums[start] < lower) continue;
            while(start - 1 >= 0 && nums[start - 1] + nums[i] >= lower) start--;
            while(end - 1 >= 0 && nums[end] + nums[i] > upper) end--;
            if (i >= end) return ans;
            if (i < start) ans += end - start + 1;
            else ans += end - i;
            // cout << nums[i] << " : " << nums[start] << " - " << nums[end] << endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3;
    int upper = 6;
    // vector<int> nums = {1,7,9,2,5};
    // int lower = 11;
    // int upper = 11;
    // vector<int> nums = {0,0,0,0,0,0};
    // int lower = 0;
    // int upper = 0;
    Solution S;
    cout << S.countFairPairs(nums, lower, upper) << endl;
    return 0;
}