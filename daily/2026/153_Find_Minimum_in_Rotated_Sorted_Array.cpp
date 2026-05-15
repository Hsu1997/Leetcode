#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            int l = nums[left];
            int r = nums[right];
            if (l <= r) return l;
            int mid = left + (right - left) / 2;
            int m = nums[mid];
            if (m >= l) left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};

int main(){
    vector<int> nums = {3,4,5,1,2};
    // vector<int> nums = {4,5,6,7,0,1,2};
    // vector<int> nums = {11,13,15,17};
    // vector<int> nums = {1};
    // vector<int> nums = {2,1};
    Solution S;
    cout << S.findMin(nums) << endl;
    return 0;
}