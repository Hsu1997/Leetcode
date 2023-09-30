#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int f = 0;
        int t = nums.size()-1;
        int mid;
        while(f <= t){
            mid = (f+t)/2;
            if (mid == 0 || mid == n-1){
                if (mid == 0 && nums[0] == nums[1]) f = 2;
                else if (mid == n-1 && nums[mid] == nums[mid-1]) t = mid-2;
                else return nums[mid];
            }
            else{
                if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
                if (nums[mid & (INT_MAX << 1)] == nums[mid | 1]) f = (mid|1)+1;
                else t = mid - 1;
            }
            
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    // vector<int> nums = {3,3,7,7,10,11,11};
    Solution S;
    cout << S.singleNonDuplicate(nums) << endl;
    return 0;
}