#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int convert(vector<int>& count){
        int ans = 0;
        for (int i = 0; i < 32; i++){
            if (count[i]) ans += (1 << i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int temp = 0;
        for (int i : nums){
            if (i >= k) return 1;
            temp |= i;
        }
        if (temp < k) return -1;
        int n = nums.size();
        int ans = n;
        int left = 0;
        int right = 0;
        vector<int> count(32, 0);
        while(left < n){
            while(convert(count) < k && right < n){
                // cout << "Add " << nums[right] << " : ";
                for (int i = 0; i < 32; i++){
                    if ((nums[right] >> i) & 1) count[i]++;
                }
                right++;
                // cout << convert(count) << endl;
            }
            if (convert(count) < k) return ans;
            while(convert(count) >= k && left < n){
                // cout << "Now = " << convert(count) << ", delete " << nums[left] << endl;
                ans = min(ans, right - left);
                // cout << "temp len = " << right - left << endl;
                for (int i = 0; i < 32; i++){
                    if ((nums[left] >> i) & 1) count[i]--;
                }
                left++;
            }
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,3};
    // int k = 2;
    // vector<int> nums = {2,1,8};
    // int k = 10;
    vector<int> nums = {1,2};
    int k = 0;
    Solution S;
    cout << S.minimumSubarrayLength(nums, k) << endl;
    return 0;
}