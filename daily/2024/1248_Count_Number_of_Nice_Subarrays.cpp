#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = -1;
        int odd = 0;
        while (right < n && odd < k){
            if (nums[++right] % 2) odd++;
        }
        // cout << left << " " << right << endl;
        if (odd < k) return 0;
        int pre_left = -1;
        int pre_right = right;
        while(right < n){
            while(nums[left] % 2 == 0) left++;
            right++;
            while(right < n && nums[right] % 2 == 0) right++;
            ans += (left - pre_left) * (right - pre_right);
            pre_left = left;
            left++;
            pre_right = right;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,1,2,1,1};
    // int k = 3;
    // vector<int> nums = {2,4,6};
    // int k = 1;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    Solution S;
    cout << S.numberOfSubarrays(nums, k) << endl;
    return 0;
}