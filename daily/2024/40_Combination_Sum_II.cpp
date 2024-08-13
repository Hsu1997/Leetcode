#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& candidates, int target, vector<int>& temp, int acc, int i){
        if (target == acc) ans.push_back(temp);
        if (i == candidates.size() || acc > target) return;
        for (int next = i; next < candidates.size(); next++){
            if (next == i || candidates[next - 1] != candidates[next]){
                temp.push_back(candidates[next]);
                helper(candidates, target, temp, acc + candidates[next], next + 1);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp = {};
        helper(candidates, target, temp, 0, 0);
        return ans;
    }
};

int main(){
    // vector<int> candidates = {10,1,2,7,6,1,5};
    // int target = 8;
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    Solution S;
    vector<vector<int>> ans = S.combinationSum2(candidates, target);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}