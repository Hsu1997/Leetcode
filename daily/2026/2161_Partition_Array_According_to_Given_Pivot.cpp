#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int ptr = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] < pivot) ans[ptr++] = nums[i];
            else if (nums[i] == pivot) cnt++;
        }
        while(cnt--) ans[ptr++] = pivot;
        for (int i = 0; i < n; i++){
            if (nums[i] > pivot) ans[ptr++] = nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    // vector<int> nums = {-3,4,3,2};
    // int pivot = 2;
    Solution S;
    vector<int> ans = S.pivotArray(nums, pivot);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}