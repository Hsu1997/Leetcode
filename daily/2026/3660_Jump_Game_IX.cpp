#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        // [all left nums] <= [all right nums]
        // prefixMin[i] <= suffixMax[i+1] => cur at [i] | [i+1]
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }
        suffixMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--){
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }
        int ptr = 0;
        int currMax = 0;
        vector<int> ans(n);
        for (int i = 0; i < n - 1; i++){
            currMax = max(currMax, nums[i]);
            if (prefixMax[i] <= suffixMin[i+1]){
                while(ptr <= i) ans[ptr++] = currMax;
            }
        }
        currMax = max(currMax, nums[n-1]);
        while(ptr < n) ans[ptr++] = currMax;
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,3};
    // vector<int> nums = {2,3,1};
    Solution S;
    vector<int> ans = S.maxValue(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}