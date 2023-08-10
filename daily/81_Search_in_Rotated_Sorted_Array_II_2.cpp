#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid]){
                l++;
                continue;
            }
            bool pivot_in_first = nums[mid] >= nums[l];
            bool target_in_first = target >= nums[l];
            if (pivot_in_first ^ target_in_first){
                if (pivot_in_first) l = mid+1;
                else r = mid-1;
            }
            else{
                if (target > nums[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        return false;
    }
};

int main(){
    // vector<int> nums = {2,5,6,0,0,1,2};
    // int target = 0;
    // vector<int> nums = {2,5,6,0,0,1,2};
    // int target = 3;
    vector<int> nums = {1,0,1,1,1};
    int target = 0;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}