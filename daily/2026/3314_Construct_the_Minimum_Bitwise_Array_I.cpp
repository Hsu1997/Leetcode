#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int num : nums){
            int k = (~num) & (num + 1);
            if (k == 1) ans.push_back(-1);
            else ans.push_back(num - (k >> 1));
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,5,7};
    // vector<int> nums = {11,13,31};
    // vector<int> nums = {47};
    Solution S;
    vector<int> ans = S.minBitwiseArray(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}