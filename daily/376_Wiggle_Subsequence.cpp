#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subproblem(vector<int>& nums, int dirction){
        int prev = nums[0];
        int ans = 1;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == prev) continue;
            
            // cout << nums[i] << " : ";
            if (dirction * prev < dirction * nums[i]){
                dirction *= -1;
                ans++;
            }
            prev = nums[i];
            // cout << dirction <<  ", prev = " << prev << ", ans = " << ans << endl;
        }
        return ans;
    }

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;        
        return max(subproblem(nums, 1), subproblem(nums, -1));
    }
};

int main(){
    // vector<int> nums = {3,3,3,2,5};
    // vector<int> nums = {8,1,7,4,9,2,5};
    // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Solution S;
    cout << S.wiggleMaxLength(nums) << endl;
    return 0;
}