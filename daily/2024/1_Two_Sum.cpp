#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++){
            if (m.find(target - nums[i]) != m.end()) return {m[target - nums[i]], i};
            else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    // vector<int> nums = {3,2,4};
    // int target = 6;
    // vector<int> nums = {3,3};
    // int target = 6;
    Solution S;
    vector<int> ans = S.twoSum(nums, target);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}