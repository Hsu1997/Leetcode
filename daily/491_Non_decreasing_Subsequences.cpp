#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> s;
    int n;

    void dfs(vector<int>& nums, int k, vector<int>& now){
        if (k >= n || (!now.empty() && nums[k] < now.back())) return;
        now.push_back(nums[k]);
        if (now.size() >= 2) s.insert(now);
        for (int i = k+1; i < n; i++){
            dfs(nums, i, now);
        }
        now.pop_back();
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> now;
        for (int i = 0; i < n; i++) dfs(nums, i, now);
        return vector(s.begin(), s.end());   
    }
};

int main(){
    vector<int> nums = {4,6,7,7};
    Solution S;
    vector<vector<int>> ans = S.findSubsequences(nums);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}