#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heapify(vector<int>&nums, int i, int limit){
        int temp_max = i;
        int left = i*2+1;
        int right = i*2+2;
        if (left < limit && nums[left] > nums[temp_max]) temp_max = left;
        if (right < limit && nums[right] > nums[temp_max]) temp_max = right;
        if (temp_max != i){
            swap(nums[i], nums[temp_max]);
            heapify(nums, temp_max, limit);
        }
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = (n-1)/2; i >= 0; i--) heapify(nums, i, n);
        for (int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    // vector<int> nums = {5,1,1,2,0,0};
    Solution S;
    vector<int> ans = S.sortArray(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}