#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> acc_mod(n);
        acc_mod[0] = nums[0] % p;
        if (acc_mod[0] == 0) ans = n-1;
        for (int i = 1; i < n; i++){
            acc_mod[i] = (nums[i] + acc_mod[i-1]) % p;
            if (acc_mod[i] == 0) ans = n - 1 - i;
        }
        if (ans == 0) return ans;
        // for (int i : acc_mod) cout << i << " ";
        // cout << endl;
        int subtract = acc_mod.back();
        // vector<int> last_mod(p, -1);
        unordered_map<int,int> last_mod;
        for (int i = 0; i < n; i++){
            // search subarray accumulate module == 'subtract'
            if (nums[i] % p == subtract) return 1;
            if (acc_mod[i] == subtract && i != n-1) ans = min(ans, i + 1);
            int needed = acc_mod[i] - subtract;
            if (needed < 0) needed += p;
            if (last_mod.find(needed) != last_mod.end()) ans = min(ans, i - last_mod[needed]);
            last_mod[acc_mod[i]] = i;
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    vector<int> nums = {3,1,4,2};
    int p = 6;
    // vector<int> nums = {6,3,5,2};
    // int p = 9;
    // vector<int> nums = {1,2,3};
    // int p = 3;
    // vector<int> nums = {1,2,3};
    // int p = 7;
    // vector<int> nums = {8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    // int p = 148;
    Solution S;
    cout << S.minSubarray(nums, p) << endl;
    return 0;
}