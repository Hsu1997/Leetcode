#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int idx = 0;
        for (int i = 0; i < n - 1; i++){
            if (nums[i] == 0) continue;
            if (nums[i] == nums[i+1]){
                ans[idx++] = 2 * nums[i];
                nums[i+1] = 0;
            }
            else ans[idx++] = nums[i];
        }
        ans[idx] = nums[n-1];
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2,1,1,0};
    // vector<int> nums = {0,1};
    // vector<int> nums = {847,847,0,0,0,399,416,416,879,879,206,206,206,272};
    // vector<int> nums = {312,312,436,892,0,0,528,0,686,516,0,0,0,0,0,445,445,445,445,445,445,984,984,984,0,0,0,0,168,0,0,647,41,203,203,241,241,0,628,628,0,875,875,0,0,0,803,803,54,54,852,0,0,0,958,195,590,300,126,0,0,523,523};
    Solution S;
    vector<int> ans = S.applyOperations(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}