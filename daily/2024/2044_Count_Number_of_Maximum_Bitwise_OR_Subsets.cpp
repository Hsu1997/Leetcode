#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, int i, int curr, int target){
        if (i == nums.size()) return;
        dfs(nums, i+1, curr, target);
        curr |= nums[i];
        if (curr == target) ans += 1 << (nums.size() - 1 - i);
        else{
            dfs(nums, i+1, curr, target);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for (int i : nums) target |= i;
        dfs(nums, 0, 0, target);
        return ans;
    }
};

int main(){
    vector<int> nums = {3,1};
    // vector<int> nums = {2,2,2};
    // vector<int> nums = {3,2,1,5};
    Solution S;
    cout << S.countMaxOrSubsets(nums) << endl;
    return 0;
}