#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = nums[(i + n + nums[i] % n) % n];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,-2,1,1};
    // vector<int> nums = {-1,4,-1};
    Solution S;
    vector<int> ans = S.constructTransformedArray(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}