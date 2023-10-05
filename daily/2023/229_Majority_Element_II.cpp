#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        for (auto i : nums){
            m[i]++;
            if (m[i] == nums.size()/3 + 1) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,2,3};
    // vector<int> nums = {1};
    // vector<int> nums = {1,2};
    Solution S;
    vector<int> ans = S.majorityElement(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}