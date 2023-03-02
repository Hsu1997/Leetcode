#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;

    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp(right - left + 1);
        int i = left;
        int j = mid+1;
        int k = 0;
        while(i <= mid && j <= right){
            if (nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= right) temp[k++] = nums[j++];
        for (i = left, k = 0; i <= right; i++, k++) nums[i] = temp[k];
    }

    void mergesort(vector<int>& nums, int left, int right){
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        n = nums.size();
        mergesort(nums, 0, n-1);
        return nums;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    // vector<int> nums = {5,1,1,2,0,0};
    Solution S;
    vector<int> ans = S.sortArray(nums);
    for (auto i : ans) cout << i << " ";
    return 0;
}