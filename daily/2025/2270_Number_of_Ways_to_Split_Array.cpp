#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long left = 0;
        long right = 0;
        int ans = 0;
        for (int i : nums) right += i;
        for (int i = 0; i < nums.size()-1; i++){
            left += nums[i];
            right -= nums[i];
            if (left >= right) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,4,-8,7};
    // vector<int> nums = {2,3,1,0};
    Solution S;
    cout << S.waysToSplitArray(nums) << endl;
    return 0;
}