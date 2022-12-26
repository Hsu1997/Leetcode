#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int max_range = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i > max_range) return false;
            max_range = max(max_range, i + nums[i]);
            // cout << max_range << " ";
            if (max_range >= n) return true;
        }
        // cout << endl;
        return false;
    }
};

int main(){
    // vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {3,2,1,0,4};
    vector<int> nums = {1,1,2,2,0,1,1};
    Solution S;
    cout << S.canJump(nums) << endl;
    return 0;
}