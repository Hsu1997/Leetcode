#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int significant = 0;
        for (int i : nums) significant ^= i;
        if (significant != INT_MIN) significant &= -significant;
        vector<int> ans(2);
        for (int i : nums){
            if (i & significant) ans[0] ^= i;
            else ans[1] ^= i;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,3,2,5};
    // vector<int> nums = {-1,0};
    // vector<int> nums = {0,1};
    Solution S;
    vector<int> ans = S.singleNumber(nums);
    for (auto i : ans) cout << i <<  " ";
    cout << endl;
    return 0;
}