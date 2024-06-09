#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod(k, 0);
        mod[0] = 1;
        int ans = 0;
        int acc = 0;
        for (auto i : nums){
            acc = (acc + i) % k;
            if (acc < 0) acc += k;
            ans += mod[acc]++;
            // for (auto j : mod) cout << j << " ";
            // cout << " => ans = " << ans << endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    // vector<int> nums = {5};
    // int k = 9;
    Solution S;
    cout << S.subarraysDivByK(nums, k) << endl;
    return 0;
}