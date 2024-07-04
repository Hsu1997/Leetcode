#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int i, int n){
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;
    if (left < n && nums[largest] < nums[left]) largest = left;
    if (right < n && nums[largest] < nums[right]) largest = right;
    if (largest != i){
        swap(nums[i], nums[largest]);
        helper(nums, largest, n);
    }
}

void HeapSort(vector<int>& nums){
    int n = nums.size();
    for (int i = n/2-1; i >= 0; i--){
        helper(nums, i, n);
    }
    for (int i = n-1; i >= 0; i--){
        swap(nums[0], nums[i]);
        helper(nums, 0, i);
    }
}

int main(){
    vector<int> nums = {2,3,5,1,4,8,5,3,1,10,100,24,1,1,2};
    for (auto i : nums) cout << i << " ";
    cout << endl;
    HeapSort(nums);
    for (auto i : nums) cout << i << " ";
    cout << endl;
    return 0;
}