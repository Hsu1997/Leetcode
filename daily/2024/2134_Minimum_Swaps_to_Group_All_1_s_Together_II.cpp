#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        for (int i : nums) if (i == 1) one++;
        int count = 0;
        for (int i = 0; i < one; i++) if (nums[i] == 1) count++;
        int ans = one - count;
        for (int begin = 0; begin < n; begin++){
            int del = begin;
            int add = (begin + one) % n;
            // cout << "del " << del << " add " << add << " : " << one - count << endl;
            count = count - (nums[del] == 1) + (nums[add] == 1);
            ans = min(ans, one - count);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,1,0,1,1,0,0};
    // vector<int> nums = {0,1,1,1,0,0,1,1,0};
    // vector<int> nums = {1,1,0,0,1};
    Solution S;
    cout << S.minSwaps(nums) << endl;
    return 0;
}