#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int mod = 1e9+7;
        sort(nums.begin(), nums.end());

        vector<int> pre_pow = {1};
        for (int k = 1; k <= n; k++){
            pre_pow.push_back((pre_pow.back()*2) % mod);
        }
        
        int i = 0;
        int j = n-1;
        while(i <= j){
            while(j >= i && nums[i] + nums[j] > target) j--;
            if (j < i) return ans;
            ans += pre_pow[j-i];
            ans %= mod;
            i++;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {3,5,6,7};
    // int target = 9;
    // vector<int> nums = {3,3,6,8};
    // int target = 10;
    // vector<int> nums = {2,3,3,4,6,7};
    // int target = 12;
    vector<int> nums = {9,25,9,28,24,12,17,8,28,7,21,25,10,2,16,19,12,13,15,28,14,12,24,9,6,7,2,15,19,13,30,30,23,19,11,3,17,2,14,20,22,30,12,1,11,2,2,20,20,27,15,9,10,4,12,30,13,5,2,11,29,5,3,13,22,5,16,19,7,19,11,16,11,25,29,21,29,3,2,9,20,15,9};
    int target = 32;
    Solution S;
    cout << S.numSubseq(nums, target) << endl;
    return 0;
}