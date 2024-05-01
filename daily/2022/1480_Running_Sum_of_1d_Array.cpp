#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        int accumulate = 0;
        for (auto i : nums){
            accumulate += i;
            ans.push_back(accumulate);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution S;
    vector<int> ans = S.runningSum(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}