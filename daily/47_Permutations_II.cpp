#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> map;
    int length;

    void subproblem(unordered_map<int, int> &map, vector<int> &curr){
        if (curr.size() == length) ans.push_back(curr);
        else{
            for (auto [key, value] : map){
                if (value == 0) continue;
                map[key]--;
                curr.push_back(key);
                subproblem(map, curr);
                curr.pop_back();
                map[key]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        length = nums.size();
        for (int i : nums) map[i]++;
        // for (auto it : map) cout << it.first << " " << it.second << endl;
        vector<int> curr;
        subproblem(map, curr);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution S;
    vector<vector<int>> ans = S.permuteUnique(nums);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}