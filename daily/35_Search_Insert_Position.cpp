#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    if (target < nums[0]) return 0;
    int f = 0;
    int t = nums.size()-1;
    while(f < t){
        int mid = (f + t) / 2;
        // cout << f << " " << t << endl;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) t = mid - 1;
        else f = mid + 1;
    }
    return (target > nums[t])? t+1 : t;
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    // int target = 5;
    // int target = 2;
    int target = 7;
    Solution S;
    cout << S.searchInsert(nums, target) << endl;
    return 0;
}