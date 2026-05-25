#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid + 1;
        }
        int start = right;
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if (nums[(m + start) % n] == target) return (m + start) % n;
            if (nums[(m + start) % n] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int target = 3;
    // vector<int> nums = {1};
    // int target = 0;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}