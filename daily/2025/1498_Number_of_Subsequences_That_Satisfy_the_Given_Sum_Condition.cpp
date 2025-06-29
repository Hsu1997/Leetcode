#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> create_pow_mod_table(int n, int mod){
        vector<int> table(n+1, 0);
        table[0] = 1;
        for (int i = 1; i <= n; i++){
            table[i] = (table[i-1] * 2) % mod;
        }
        return table;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int mod = 1e9 + 7;
        vector<int> table = create_pow_mod_table(n, mod);
        int ptr = n - 1;
        for (int i = 0; i < n; i++){
            while(ptr >= 0 && nums[i] + nums[ptr] > target) ptr--;
            if (i > ptr) break;
            ans = (ans + table[ptr - i]) % mod;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,5,6,7};
    int target = 9;
    // vector<int> nums = {3,3,6,8};
    // int target = 10;
    // vector<int> nums = {2,3,3,4,6,7};
    // int target = 12;
    Solution S;
    cout << S.numSubseq(nums, target) << endl;
    return 0;
}