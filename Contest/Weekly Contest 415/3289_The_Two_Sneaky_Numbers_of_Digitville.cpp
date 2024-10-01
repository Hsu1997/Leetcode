#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s;
        for (int i : nums){
            if (s.find(i) != s.end()) ans.push_back(i);
            else s.insert(i);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,1,1,0};
    // vector<int> nums = {0,3,2,1,3,2};
    // vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    Solution S;
    vector<int> ans = S.getSneakyNumbers(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}