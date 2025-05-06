#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = nums[nums[i]];
        return ans;
    }
};

int main(){
    vector<int> nums = {0,2,1,5,3,4};
    // vector<int> nums = {5,0,1,2,3,4};
    Solution S;
    vector<int> ans = S.buildArray(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}