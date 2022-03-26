#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int pivot = left + (right - left) / 2;
            if (nums[pivot] == target) return pivot;
            if (nums[pivot] < target) left = pivot + 1;
            if (nums[pivot] > target) right = pivot - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}