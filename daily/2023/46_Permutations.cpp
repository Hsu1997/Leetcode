#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void subprob(vector<int>& nums, int s){
        if (s == n) ans.push_back(nums);
        else{
            for (int i = s; i < n; i++){
                swap(nums[s], nums[i]);
                subprob(nums, s+1);
                swap(nums[s], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        subprob(nums, 0);
        // cout << ans.size() << endl;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {0,1};
    // vector<int> nums = {1};
    Solution S;
    vector<vector<int>> ans = S.permute(nums);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}