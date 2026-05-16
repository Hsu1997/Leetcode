#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) r = m;
            else if (nums[m] > nums[r]) l = m + 1;
            else r--;
        }
        return nums[r];
    }
};

int main(){
    vector<int> nums = {1,3,5};
    // vector<int> nums = {2,2,2,0,1};
    Solution S;
    cout << S.findMin(nums) << endl;
    return 0;
}