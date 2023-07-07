#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int total = 0;
        while(j < n && total < target){
            total += nums[j++];
        }
        if (total < target) return 0;
        while(total - nums[i] >= target){
            total -= nums[i++];
        }
        int ans = j - i;
        while(j < n){
            total += nums[j++];
            while(total >= target && i < j){
                total -= nums[i++];
                if (total >= target) ans = min(ans, j-i);
            }
        }
        return ans;
    }
};

int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    // int target = 213;
    // vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    Solution S;
    cout << S.minSubArrayLen(target, nums) << endl;
    return 0;
}