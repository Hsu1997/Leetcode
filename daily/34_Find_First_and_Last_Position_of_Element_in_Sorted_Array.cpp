#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        if (nums.size() == 1){
            if (nums[0] == target) return {0,0};
            else return {-1,-1};
        }
        int start = -1;
        int end = -1;
        int left = 0;
        int right = nums.size()-1;
        int find = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else{
                find = mid;
                break;
            }
        }
        if (find == -1) return {-1,-1};

        start = end = find;
        while(left < start){
            int mid = left + (start - left)/2;
            if (nums[mid] != target) left = mid + 1;
            else start = mid;
        }
        
        if (nums[right] == target) return {start, right};
        // find the first number which is not equal the target.
        while(end < right){
            int mid = end + (right - end)/2;
            if (nums[mid] != target) right = mid;
            else end = mid + 1;
        }

        return {start, end - 1};
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    // vector<int> nums = {5,7,7,8,8,10};
    // int target = 6;
    // vector<int> nums = {1,4};
    // int target = 4;
    
    Solution S;
    vector<int> ans = S.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}