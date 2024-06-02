#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans = {{}};
    void subproblem(vector<int>& nums, int index, vector<int>& temp){
        if (index == nums.size()) return;
        subproblem(nums, index+1, temp);
        temp.push_back(nums[index]);
        ans.push_back(temp);
        subproblem(nums, index+1, temp);
        temp.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp = {};
        subproblem(nums, 0, temp);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {0};
    Solution S;
    vector<vector<int>> ans = S.subsets(nums);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}