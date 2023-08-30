#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = n-2; i >= 0; i--){
            if (nums[i] <= nums[i+1]) continue;
            int amount = (nums[i]/nums[i+1]) + (nums[i]%nums[i+1] != 0);
            ans += amount-1;
            nums[i] /= amount;
        }
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        return ans;
    }
};

int main(){
    vector<int> nums = {3,9,3};
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1000000000,1000000000,1000000000,1000000000,1000000,1000000000,1000000000,4444,3,1};
    // vector<int> nums = {12,9,7,6,17,19,21};
    Solution S;
    cout << S.minimumReplacement(nums) << endl;
    return 0;
}