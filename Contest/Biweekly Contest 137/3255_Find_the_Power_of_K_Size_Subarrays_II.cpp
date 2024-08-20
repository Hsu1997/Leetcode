#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int continuous = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] - nums[i-1] == 1) continuous++;
            else continuous = 1;
            if (continuous == k) ans[i - (k - 1)] = nums[i], continuous--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;
    // vector<int> nums = {2,2,2,2,2};
    // int k = 4;
    // vector<int> nums = {3,2,3,2,3,2};
    // int k = 2;
    Solution S;
    vector<int> ans = S.resultsArray(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}