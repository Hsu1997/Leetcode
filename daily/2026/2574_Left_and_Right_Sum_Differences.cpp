#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int res = 0;
        for (int i = 0; i < n; i++){
            ans[i] = res;
            res += nums[i];
        }
        res = 0;
        for (int i = n - 1; i >= 0; i--){
            ans[i] -= res;
            res += nums[i];
            if (ans[i] < 0) ans[i] *= -1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,4,8,3};
    // vector<int> nums = {1};
    Solution S;
    vector<int> ans = S.leftRightDifference(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}