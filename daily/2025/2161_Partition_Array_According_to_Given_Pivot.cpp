#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int pivot_count = 0;
        int idx = 0;
        for (int n : nums){
            if (n < pivot) ans[idx++] = n;
            else if (n == pivot) pivot_count++;
            else continue;
        }
        while(pivot_count--) ans[idx++] = pivot;
        for (int n : nums) if (n > pivot) ans[idx++] = n;
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