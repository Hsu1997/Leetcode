#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int max_element = nums[0];
        int continuous = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]) continuous++;
            else continuous = 1;
            if (nums[i] > max_element){
                max_element = nums[i];
                ans = continuous;
            }
            else if (nums[i] == max_element){
                ans = max(ans, continuous);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,3,2,2};
    // vector<int> nums = {1,2,3,4};
    Solution S;
    cout << S.longestSubarray(nums) << endl;
    return 0;
}