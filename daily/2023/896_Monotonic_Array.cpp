#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increase = true;
        bool decrease = true;
        for (int i = 0; i < n-1; i++){
            if (nums[i+1] > nums[i]) decrease = false;
            if (nums[i+1] < nums[i]) increase = false;
            if (!increase && !decrease) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,2,2,3};
    // vector<int> nums = {6,5,4,4};
    // vector<int> nums = {1,3,2};
    Solution S;
    cout << S.isMonotonic(nums) << endl;
    return 0;
}