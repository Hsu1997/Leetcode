#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> count(nums.size()+1);
        vector<int> ans(2);
        for (auto i : nums) count[i]++;
        for (int i = 1; i < count.size(); i++){
            if (count[i] == 2) ans[0] = i;
            if (count[i] == 0) ans[1] = i;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,2,4};
    // vector<int> nums = {1,1};
    vector<int> nums = {2,2};
    Solution S;
    vector<int> ans = S.findErrorNums(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}