#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int acc = nums[0];
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i-1]) acc += nums[i];
            else acc = nums[i];
            ans = max(ans, acc);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,20,30,5,10,50};
    // vector<int> nums = {10,20,30,40,50};
    // vector<int> nums = {12,17,15,13,10,11,12};
    Solution S;
    cout << S.maxAscendingSum(nums) << endl;
    return 0;
}