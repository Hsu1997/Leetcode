#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr_pos = 0;
        int curr_neg = 0;
        int ans = 0;
        for (int num : nums){
            curr_pos += num;
            curr_neg += num;
            curr_pos = max(curr_pos, 0);
            curr_neg = min(curr_neg, 0);
            ans = max(ans, max(curr_pos, abs(curr_neg)));
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,-3,2,3,-4};
    // vector<int> nums = {2,-5,1,-4,3,-2};
    Solution S;
    cout << S.maxAbsoluteSum(nums) << endl;
    return 0;
}