#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int M = (1 << maximumBit) - 1;
        int acc = 0;
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--){
            acc = acc ^ nums[n-1-i];
            ans[i] = acc ^ M;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,1,1,3};
    int maximumBit = 2;
    // vector<int> nums = {2,3,4,7};
    // int maximumBit = 3;
    // vector<int> nums = {0,1,2,2,5,7};
    // int maximumBit = 3;
    Solution S;
    vector<int> ans = S.getMaximumXor(nums, maximumBit);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}